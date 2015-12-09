#include "Robot.hpp"
#include "Arduino.h"

Robot *Robot::instance = NULL;

Robot::Robot()
  {
}

void Robot::setup(){
  lidar.setup();
  base.setup();
  ff.setup();
}

Robot *Robot::getInstance(){
  if(instance == NULL){
    instance = new Robot();
  }
  return instance;

}

void Robot::drive(){
  switch (this->driveDirection){
    case DriveDirection::FORWARD:
      base.setSpeeds(10,10);
      break;
    case DriveDirection::LEFT:
      base.setSpeeds(-10,10);
      break;
    case DriveDirection::RIGHT:
      base.setSpeeds(10,-10);
      break;
    case DriveDirection::BACKWARD:
      base.setSpeeds(-10,-10);
      break;
  }
}

void Robot::stop(){
  base.stop();
}

void Robot::setDrive(DriveDirection dir){
  this->driveDirection = dir;
}

bool Robot::search(){
  driveAndAvoid();
  if (detector.detect(&distanceToCandle, &angleToCandle, distances))
  {
     return true;
  }
  return false;
}

bool Robot::driveToCandle(){
  if(turnToFace(angleToCandle)){
        search();
        if(distanceToCandle < GOAL_DISTANCE){
            stop();
            ff.startScan();
            return true;
        }
    }
    return false;
}

bool Robot::findCandleHeight(){
    ff.watch(distanceToCandle);
    return false;
}

bool Robot::extinguishCandle(){
  return false;
}

bool Robot::returnToOrigin(){
  return false;
}

bool  Robot::turnToFace(int angle){
  //turn so that angle will become zero
  //if angle is within 5 degrees, end
  //this is really dumb and should be fixed
  int power = 0;
  double kP = .5;
  if (abs(angle < 5)){
    stop();
    return true;
  }
  else if (angle > 180){
    power = (360-angle)*kP;
    base.setSpeeds(power,-power);

  }
  else {
    power = (360-angle)*kP;
    base.setSpeeds(-power,power);
  }
  return false;

}

void Robot::driveAndAvoid(){
  DriveDirection dir = searcher.getDirection();
  setDrive(dir);
  drive();
}

