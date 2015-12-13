#include "Searcher.hpp"
#include "../main.hpp"
#include "Arduino.h"
#include "../test/Robot.hpp"

Searcher::Searcher() : state(SEARCHING) {}

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
    case CHECKING:
      switch(check()){
        case THINKING:
          break;
        case FOUND:
          state = TURN_TO_CANDLE;
          break;
        case MISTAKEN:
          state = SEARCHING;
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
        dirAtStartOfTurn = Robot::getInstance()->base.dir();
        auto dist = Robot::getInstance()->detector.distance();
        auto angle = Robot::getInstance()->detector.angle();
        Point<float> relative(dist*cos(angle*M_PI/180)/25.4, dist*sin(angle*M_PI/180)/25.4);
        auto candle_pos = Robot::getInstance()->base.odom.robotToWorld(relative);

        debugPrint(0,"x=%d y=%d", (int)candle_pos.x(), (int)candle_pos.y());
        return FOUND;
        state = TURN_TO_CANDLE;
      }
    }

    if (sweeps++ > 8){
      return MISTAKEN;
    }
  }

  return THINKING;
}

bool Searcher::driveToCandle(){
  bool fullSweep = Robot::getInstance()->lidar.read();

  if (fullSweep){
    int dFront = sampleAt(0, 3);

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

int Searcher::sampleAt(int i, int ss){
  long sum = 0;
  int start = i - ss,
      end = i + ss;

  int angle;
  int count = 0;
  for (int j=start;j<end;j++){
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
  Serial.print(sum);
  Serial.print(" ");
  Serial.println(count);
  return sum/count;
}

DriveDirection Searcher::driveAndAvoid(){
  DriveDirection dir;

  int diff = 45;
  int dFront = sampleAt(0);
  int dLeft = sampleAt(360-diff, 25);
  int dRight = sampleAt(diff, 25);

  debugPrint(1,"%d %d %d", dLeft, dFront, dRight);

  if (dFront < AVOID_DISTANCE){
    if ( dLeft > dRight ){
      dir = LEFT;
    }
    else{
      dir = RIGHT;
    }
  }
  else if ( dLeft < AVOID_DISTANCE) {
    dir = RIGHT;
  }
  else if ( dRight < AVOID_DISTANCE) {
    dir = LEFT;
  }
  else {
    dir = FORWARD;
    Robot::getInstance()->setDrive(FORWARD);
    Robot::getInstance()->base.drive();
  }

  return dir;
}
