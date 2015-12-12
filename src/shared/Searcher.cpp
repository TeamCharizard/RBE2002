#include "Searcher.hpp"
#include "../main.hpp"
#include "Arduino.h"
#include "../test/Robot.hpp"

Searcher::Searcher() : state(SEARCHING) {}

bool Searcher::run(){
  switch(state){
    case SEARCHING:
      if (search()){
        state = CHECKING;
        debugPrint(1,"sstate =%s",stateNames[state]);
      }
      break;
    case CHECKING:
      if (check()){
        dirAtStartOfTurn = Robot::getInstance()->base.dir();
        state = TURN_TO_CANDLE;
        debugPrint(1,"sstate =%s",stateNames[state]);
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
        return true;
      }
      break;
  }
  return false;
}

bool Searcher::check(){
  //make sure we ain't going anywhere
  Robot::getInstance()->stop();
  Robot::getInstance()->drive();

  bool fullSweep = Robot::getInstance()->lidar.read();

  if (fullSweep){
    bool candleFound = Robot::getInstance()->detector.detect(
        Robot::getInstance()->lidar.distances);

    if (candleFound){
      candleCount++;
      debugPrint(1,"count = %d", candleCount);
      return candleCount > 10;
    }

  }
  return false;
}

bool Searcher::driveToCandle(){
  DriveDirection dir = driveAndAvoid();
  if (dir != FORWARD){
    state = SEARCHING;
  }

  int dFront = sampleAt(Robot::getInstance()->lidar.distances, 0);

  return dFront < 500; //we're done if we're 50cm away
}

bool Searcher::turnToFaceCandle(){
  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;

    float goalDir = dirAtStartOfTurn +
      Robot::getInstance()->detector.distance() * M_PI / 180;

    if(Robot::getInstance()->turnToFaceAbsolutely(goalDir)) {
      Robot::getInstance()->stop();
      return false;
    }
  }
}

bool Searcher::search(){
  bool fullSweep = Robot::getInstance()->lidar.read();

  if (fullSweep){
    driveAndAvoid();
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

int Searcher::sampleAt(int *distances, int i){
  long s = 0;
  int ss = 10,
      start = i - ss,
      end = i + ss;

  int angle;
  int c = 0;
  for (int j=start;j<end;j++){
    angle = j;
    if (j<0){
      angle = 360 + j;
    }
    if (j > 360){
      angle = i - 360;
    }


    if (distances[angle] > 0){
      debugPrint(1,"%d %d", distances[angle], c);
      s += distances[angle];
      c++;
    }
  }


  return s/c;
}

DriveDirection Searcher::driveAndAvoid(){
  DriveDirection dir;

  int dFront = sampleAt(Robot::getInstance()->lidar.distances, 0);
  int dLeft = sampleAt(Robot::getInstance()->lidar.distances, 345);
  int dRight = sampleAt(Robot::getInstance()->lidar.distances, 15);

  if (dFront  < 500 && dFront > 0){
    if ( dLeft > dRight ){
      dir = DriveDirection::LEFT;
      Robot::getInstance()->setDrive(DriveDirection::LEFT);
    }
    else{
      dir = DriveDirection::RIGHT;
      Robot::getInstance()->setDrive(DriveDirection::RIGHT);
    }
  }
  else if ( dFront > 0){
    dir = DriveDirection::FORWARD;
    Robot::getInstance()->setDrive(DriveDirection::FORWARD);
  }
  Robot::getInstance()->base.drive();
  return dir;
}
