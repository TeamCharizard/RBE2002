#include "Searcher.hpp"
#include "../main.hpp"
#include "Arduino.h"
#include "../test/Robot.hpp"
#include <limits.h>

Searcher::Searcher() : state(SEARCHING) {}

void Searcher::setup(){
  for (int angle=0,i = -90;i<90;i++){
    angle = i;
    if (angle < 0) angle += 360;
    if(angle==0) {
      R_TH[angle] = INT_MAX;
      continue;
    }

    R_TH[angle] = abs((1.0*Robot::WIDTH) / sin(angle*M_PI/180.0));
  }
}

bool Searcher::run(){
  switch(state){
    case SEARCHING:
      if (search()){
        state = CHECKING;
        debugPrint(0,"ST:%s",stateNames[state]);
      }
      break;
    case TURNING:
      {
        long now = millis();
        if (now - lastUpdateTime > UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->turnToFaceAbsolutely(absoluteTurnGoalAngle)){
            state = SEARCHING;
            debugPrint(0,"ST:%s",stateNames[state]);
          }
        }
      }
      break;
    case SCOOT:
      {
        long now = millis();
        if (now - lastUpdateTime > UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->navigator.run()){
            state = CHECK_AFTER_SCOOT;
            debugPrint(0,"ST:%s",stateNames[state]);
          }
        }
      }
      break;
    case CHECKING:
      switch(check()){
        case THINKING:
          break;
        case FOUND:
          state = CHECK_PATH;
          debugPrint(0,"ST:%s",stateNames[state]);
          break;
        case MISTAKEN:
          state = SEARCHING;
          debugPrint(0,"ST:%s",stateNames[state]);
          break;
      }
      break;
    case CHECK_PATH:
      {
        int amountToScoot = checkPath();

        //convert to inches
        float amountToScootInches = amountToScoot/25.4;
        if (amountToScoot != 0) {
          debugPrint(0,"SCOOTING!");

          //figure out where to go
          Point<float> delta(0, amountToScootInches);
          Robot::getInstance()->setGoalInCandleFrame(delta);
          Robot::getInstance()->pushPos();
          state = SCOOT;
        }
        else {
          debugPrint(0,"CLEAR PATH!");
          Robot::getInstance()->setGoalToCandle();
          state = GO_TO_CANDLE;
        }
      }
      break;
    case CHECK_AFTER_SCOOT:
      switch(check()){
        case THINKING:
          break;
        case FOUND:
          Robot::getInstance()->setGoalToCandle();
          Robot::getInstance()->pushPos();
          state = GO_TO_CANDLE;
          debugPrint(0,"ST:%s",stateNames[state]);
          break;
        case MISTAKEN:
          state = CHECKING;
          debugPrint(0,"ST:%s",stateNames[state]);
          break;
      }
      break;
    case GO_TO_CANDLE:
      {
        long now = millis();
        if (now - lastUpdateTime > UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->navigator.run()){
            state = CHECK_FINAL;
            debugPrint(0,"ST:%s",stateNames[state]);
          }
        }
      }
      break;
    case CHECK_FINAL:
      switch (check()){
        case FOUND:
          Robot::getInstance()->pushPos();
          state = TURN_TO_CANDLE;
          debugPrint(0,"ST:%s",stateNames[state]);
          break;
        case MISTAKEN:
          state = SEARCHING;
          break;
        case THINKING:
          break;
      }
      break;
    case TURN_TO_CANDLE:
      if (turnToFaceCandle()){
        return true;
        debugPrint(0,"ST:%s",stateNames[state]);
      }
      break;
  }
  return false;
}

bool Searcher::search(){
  bool fullSweep = Robot::getInstance()->lidar.read();

  if (fullSweep){
    DriveDirection currentDriveDirection = driveAndAvoid();

    if (currentDriveDirection == LEFT){
      absoluteTurnGoalAngle = Robot::getInstance()->base.dir() - M_PI/2;
      Robot::getInstance()->pushPos();
      state = TURNING;
      debugPrint(0,"ST:%s",stateNames[state]);
      return false;
    }
    else if (currentDriveDirection == RIGHT){
      absoluteTurnGoalAngle = Robot::getInstance()->base.dir() + M_PI/2;
      Robot::getInstance()->pushPos();
      state = TURNING;
      debugPrint(0,"ST:%s",stateNames[state]);
      return false;
    }

    bool candleFound = Robot::getInstance()->detector.detect(
        Robot::getInstance()->lidar.distances);

    if (candleFound){
      return true;
    }

  }
  return false;
}

int Searcher::checkPath(){
  //go through lookup table
  //if a radius is greater than it's threshold
  //return theshold minus actual radius
  int angle;
  int maxInterference = 0;
  int maxIntAng = 0;
  int maxIntR = 0;
  for (int i = -90;i<90;i++){
    auto candleAngle = Robot::getInstance()->detector.angle();
    int angle = candleAngle + i;
    int lookup_angle = i;

    if (angle < 0) angle += 360;
    if (angle > 360) angle -= 360;

    if (i < 0) lookup_angle += 360;
    if (i > 360) lookup_angle -= 360;

    int r = Robot::getInstance()->lidar.distances[angle];

    if(r < 0) continue;
    if(r > Robot::getInstance()->detector.distance()-110) continue;

    int interferrence = R_TH[lookup_angle] - r;
    if (interferrence > 0){
      return i > 0 ? -Robot::WIDTH : Robot::WIDTH;
    }
  }

  return 0;
}

Searcher::CheckState Searcher::check(){
  bool fullSweep = Robot::getInstance()->lidar.read();

  if (fullSweep){
    //make sure we ain't going anywhere
    Robot::getInstance()->stop();
    Robot::getInstance()->base.drive();

    bool candleFound = Robot::getInstance()->detector.detect(
        Robot::getInstance()->lidar.distances);


    //start after 1 full sweep, wait for 12
    if (candleFound && sweeps > 1){
      candleCount++;
      if (candleCount > 5){

        Point<float> candle_pos = Robot::getInstance()->absoluteCandlePosition();
        //debugPrint(1,"cX= %d cY=%d", (int)candle_pos.x(), (int)candle_pos.y());

        absoluteCandleAngle = Robot::getInstance()->absoluteCandleAngle();

        sweeps = 0;
        candleCount = 0;
        return FOUND;
      }
    }

    if (sweeps++ > 12){
      sweeps = 0;
      candleCount = 0;
      return MISTAKEN;
    }
  }

  return THINKING;
}

bool Searcher::turnToFaceCandle(){
  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;


    if(Robot::getInstance()->turnToFaceAbsolutely(absoluteCandleAngle)) {
      Robot::getInstance()->stop();
      return true;
    }
  }

  return false;
}

int Searcher::sampleAt(int i, int ss){
  long sum = 0;
  int start = i - ss,
      end = i + ss;

  int angle;
  int count = 0;
  for (int j=start;j<=end;j++){
    angle = j;
    if (j<0){
      angle = 360 + j;
    }
    if (j > 360){
      angle = i - 360;
    }

    int d = Robot::getInstance()->lidar.distances[angle];
    if ( d> 0){
      sum += d;
      count++;
    }
  }
  return sum/count;
}

DriveDirection Searcher::driveAndAvoid(){
  DriveDirection dir;

  int diff = 45;
  int dFront = sampleAt(0);
  int dLeft = sampleAt(360-diff);
  int dRight = sampleAt(diff, 0);

  if (dFront < AVOID_DISTANCE && dFront > 0){
    if ( dLeft > dRight ){
      dir = LEFT;
    }
    else{
      dir = RIGHT;
    }
  }
  else if ( dLeft < AVOID_DISTANCE && dLeft > 0) {
    dir = RIGHT;
  }
  else if ( dRight < AVOID_DISTANCE && dRight > 0) {
    dir = LEFT;
  }
  else {
    dir = FORWARD;
    Robot::getInstance()->setDrive(FORWARD);
    Robot::getInstance()->base.drive();
  }

  return dir;
}
