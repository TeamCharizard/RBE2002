#include "Searcher.hpp"
#include "../main.hpp"
#include "Arduino.h"
#include "../test/Robot.hpp"

Searcher::Searcher() : state(SEARCHING) {}

void Searcher::setup(){
  for (int angle=0,i = -90;i<90;i++){
    angle = i;
    if (angle < 0) angle = 360 - i;

    R_TH[angle] = Robot::WIDTH / sin(angle);
  }
}

bool Searcher::run(){
  switch(state){
    case SEARCHING:
      if (search()){
        sweeps = 0;
        candleCount = 0;

        state = CHECKING;
        debugPrint(1,"sstate =%s",stateNames[state]);
      }
      break;
    case TURNING:
      {
        long now = millis();
        if (now - lastUpdateTime > UPDATE_PERIOD){
          lastUpdateTime = now;
          if (Robot::getInstance()->turnToFaceAbsolutely(goalDir)){
            state = SEARCHING;
            debugPrint(1,"sstate =%s",stateNames[state]);
          }
        }
      }
      break;
    case SCOOT: //drive blindly for 200mm
      {
        long now = millis();
        if (now - lastUpdateTime > UPDATE_PERIOD){
          lastUpdateTime = now;
          /*
           *if (Robot::getInstance()->driveToPoint(goalPoint)){
           *  state = CHECKING;
           *  debugPrint(1,"sstate =%s",stateNames[state]);
           *}
           */
        }
      }
      break;
    case CHECKING:
      switch(check()){
        case THINKING:
          break;
        case FOUND:
          //state = CHECK_PATH; //call this if you want scoot and stuff
          state = TURN_TO_CANDLE;
          break;
        case MISTAKEN:
          state = SEARCHING;
      }
      break;
    case CHECK_PATH:
      {
        int amountToScoot = checkPath();

        if (amountToScoot != 0) {
          //figure out where to go
          state = CHECK_PATH;
          Point<float> delta(amountToScoot,0);
          goalPoint = Robot::getInstance()->base.odom.robotToWorld(delta);
          state = SCOOT;
        }
        else {
          state = TURN_TO_CANDLE;
        }
      }
      break;
    case TURN_TO_CANDLE:
      if (turnToFaceCandle()){
        state = DRIVE_TO_CANDLE;
        debugPrint(1,"sstate =%s",stateNames[state]);
      }
      break;
    case DRIVE_TO_CANDLE:
      if (driveToCandle()){
        state = CHECK_FINAL;
      }
      break;
    case CHECK_FINAL:
      switch (check()){
        case FOUND:
          state = TURN_TO_CANDLE_FINAL;
          break;
        case MISTAKEN:
          state = SEARCHING;
          break;
        case THINKING:
          break;
      }
      break;
    case TURN_TO_CANDLE_FINAL:
      if (turnToFaceCandle()){
        return true;
        debugPrint(1,"sstate =%s",stateNames[state]);
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
      goalDir = Robot::getInstance()->base.dir() - M_PI/2;
      state = TURNING;
      debugPrint(1,"sstate =%s",stateNames[state]);
      return false;
    }
    else if (currentDriveDirection == RIGHT){
      goalDir = Robot::getInstance()->base.dir() + M_PI/2;
      state = TURNING;
      debugPrint(1,"sstate =%s",stateNames[state]);
      return false;
    }

    bool candleFound = Robot::getInstance()->detector.detect(
        Robot::getInstance()->lidar.distances);

    if (candleFound){
      debugPrint(1,"a=%-3d d=%-4d",
          Robot::getInstance()->detector.angle(),
          Robot::getInstance()->detector.angle());
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
  for (int i = -90;i<90;i++){
    auto candleAngle = Robot::getInstance()->detector.angle();
    int angle = candleAngle + i;

    if (i < 0) angle = 360 - i;

    int r = Robot::getInstance()->lidar.distances[angle];

    int interferrence = R_TH[angle] - r;
    if (interferrence > 0){
      return interferrence;
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

    debugPrint(1,"ct= %d swp=%d", candleCount, sweeps);


    if (candleFound){
      candleCount++;
      if (candleCount > 5){

        auto dist = Robot::getInstance()->detector.distance();
        auto angle = Robot::getInstance()->detector.angle();
        Point<float> relative(dist*cos(angle*M_PI/180)/25.4, dist*sin(angle*M_PI/180)/25.4);
        auto candle_pos = Robot::getInstance()->base.odom.robotToWorld(relative);

        debugPrint(0,"x=%d y=%d", (int)candle_pos.x(), (int)candle_pos.y());

        return FOUND;
      }
    }

    if (sweeps++ > 8){
      return MISTAKEN;
    }
  }

  return THINKING;
}

bool Searcher::turnToFaceCandle(){
  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;

    goalDir = dirAtStartOfTurn +
      Robot::getInstance()->detector.angle() * M_PI / 180;

    if(Robot::getInstance()->turnToFaceAbsolutely(goalDir)) {
      Robot::getInstance()->stop();
      return true;
    }
  }

  return false;
}

bool Searcher::driveToCandle(){
  bool fullSweep = Robot::getInstance()->lidar.read();

  if (fullSweep){
    DriveDirection currentDriveDirection = driveAndAvoid();

    if (currentDriveDirection == LEFT){
      goalDir = Robot::getInstance()->base.dir() - M_PI/2;
      Robot::getInstance()->path.push(Point<float>(
          Robot::getInstance()->base.x(),
          Robot::getInstance()->base.y()
      ));
      state = TURNING;
      debugPrint(1,"sstate =%s",stateNames[state]);
      return false;
    }
    else if (currentDriveDirection == RIGHT){
      goalDir = Robot::getInstance()->base.dir() + M_PI/2;
      Robot::getInstance()->path.push(Point<float>(
          Robot::getInstance()->base.x(),
          Robot::getInstance()->base.y()
      ));
      state = TURNING;
      debugPrint(1,"sstate =%s",stateNames[state]);
      return false;
    }

    int dFront = sampleAt(0);

    debugPrint(1,"dFront=%d", dFront);

    if (dFront < 1000) {
      //we're done if we're 50cm away
      return true;
    }

    DriveDirection dir = driveAndAvoid();

    if (dir != FORWARD){
      debugPrint(1,"sstate =%s",stateNames[state]);
      state = SEARCHING;
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

  debugPrint(1,"%d %d %d", dLeft, dFront, dRight);

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
