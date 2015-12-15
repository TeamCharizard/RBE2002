#include <Arduino.h>
#include <limits.h>

#include "../charizard.hpp"
#include "../Robot.hpp"
#include "Searcher.hpp"

const float Searcher::AVOID_TURN_ANGLE = 1*M_PI/4;

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

void Searcher::changeState(State state){
  this->state =  state;
  StatusManager::printState(stateNames[state]);
}

bool Searcher::run(){
  switch(state){
    case SEARCHING:
      if (search()){
        changeState(CHECKING);
      }
      break;
    case TURNING:
      {
        long now = millis();
        if (now - lastUpdateTime > Robot::UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->turnToFaceAbsolutely(absoluteTurnGoalAngle)){
            changeState(SEARCHING);
          }
        }
      }
      break;
    case SCOOT:
      {
        long now = millis();
        if (now - lastUpdateTime > Robot::UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->navigator.run()){
            changeState(CHECK_AFTER_SCOOT);
          }
        }
      }
      break;
    case CHECKING:
      switch(check()){
        case THINKING:

          break;
        case FOUND:
          //set this the first time you find the candle to be more accurate
          Robot::getInstance()->setFinalAbsoluteCandlePosition();
          changeState(CHECK_PATH);
          break;
        case MISTAKEN:
          changeState(SEARCHING);
          break;
      }
      break;
    case CHECK_PATH:
      {
        int amountToScoot = checkPath();

        //convert to inches
        float amountToScootInches = amountToScoot/25.4;
        if (amountToScoot != 0) {

          //figure out where to go
          Point<float> delta(0, amountToScootInches);
          Robot::getInstance()->setGoalInCandleFrame(delta);
          Robot::getInstance()->pushPos();
          changeState(SCOOT);
        }
        else {
          int distToCandleInches = Robot::getInstance()->detector.distance() / 25.4;
          bool tooClose = distToCandleInches < Robot::CANDLE_APPROACH_DISTANCE_INCHES;
          if (!tooClose){
            Robot::getInstance()->setGoalToCandle();
            changeState(GO_TO_CANDLE);
          }
          else {
            changeState(TURN_TO_CANDLE);
          }
        }
      }
      break;
    case CHECK_AFTER_SCOOT:
      switch(check()){
        case THINKING:
          break;
        case FOUND:
          {
            int distToCandleInches = Robot::getInstance()->detector.distance() / 25.4;
            bool tooClose = distToCandleInches < Robot::CANDLE_APPROACH_DISTANCE_INCHES;
            if (!tooClose){
              Robot::getInstance()->setGoalToCandle();
              Robot::getInstance()->pushPos();
              changeState(GO_TO_CANDLE);
            }
            else {
              changeState(TURN_TO_CANDLE);
            }
          }
          break;
        case MISTAKEN:
          changeState(CHECKING);
          break;
      }
      break;
    case GO_TO_CANDLE:
      {
        long now = millis();
        if (now - lastUpdateTime > Robot::UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->navigator.run()){
            //changeState(CHECK_FINAL);
            changeState(TURN_TO_CANDLE);
          }
        }
      }
      break;
    case CHECK_FINAL:
      switch (check()){
        case FOUND:
          Robot::getInstance()->pushPos();
          changeState(TURN_TO_CANDLE);
          break;
        case MISTAKEN:
          changeState(SEARCHING);
          break;
        case THINKING:
          break;
      }
      break;
    case TURN_TO_CANDLE:
      if (turnToFaceCandle()){
        return true;
        StatusManager::printState(stateNames[state]);
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
      absoluteTurnGoalAngle = Robot::getInstance()->base.dir() - AVOID_TURN_ANGLE;
      Robot::getInstance()->pushPos();
      changeState(TURNING);
      return false;
    }
    else if (currentDriveDirection == RIGHT){
      absoluteTurnGoalAngle = Robot::getInstance()->base.dir() + AVOID_TURN_ANGLE;
      Robot::getInstance()->pushPos();
      changeState(TURNING);
      return false;
    }

    bool candleFound = Robot::getInstance()->detector.detect();

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
    if (angle > 359) angle -= 360;

    if (i < 0) lookup_angle += 360;
    if (i > 359) lookup_angle -= 360;

    int r = Robot::getInstance()->lidar.distances[angle];

    if(r < 0) continue;
    if(r > Robot::getInstance()->detector.distance()-12*25.4) continue;

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

    bool candleFound = Robot::getInstance()->detector.detect();


    //start after 1 full sweep, wait for 12
    if (candleFound && sweeps > 1){
      candleCount++;
      if (candleCount > 5){
        sweeps = 0;
        candleCount = 0;
        absoluteCandleAngle = Robot::getInstance()->absoluteCandleAngleFromCurrentPosition();
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
  if (now - lastUpdateTime > Robot::UPDATE_PERIOD){
    lastUpdateTime = now;

    if(Robot::getInstance()->turnToFaceAbsolutely(absoluteCandleAngle)) {
      return true;
    }
  }

  return false;
}

int Searcher::minInSample(int i, int ss){
  int minDistance = 6000;
  int start = i - ss,
      end = i + ss;

  int angle;
  int count = 0;
  for (int j=start;j<=end;j++){
    angle = j;
    if (j<0){
      angle = 360 + j;
    }
    if (j > 359){
      angle = i - 360;
    }

    int d = Robot::getInstance()->lidar.distances[angle];
    if ( d > 0){
      if (d < minDistance){
        minDistance = d;
      }
      count++;
    }
  }

  Serial.println(minDistance);
  return minDistance;
}

DriveDirection Searcher::driveAndAvoid(){
  DriveDirection dir;

  int diff = 50;
  int dFront = minInSample(0);
  int dLeft = minInSample(360-diff);
  int dRight = minInSample(diff, 0);

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
