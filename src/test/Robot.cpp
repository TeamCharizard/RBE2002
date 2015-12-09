#include "Robot.hpp"
#include "Arduino.h"

Robot *Robot::instance = NULL;

Robot::Robot()
  {
}

void Robot::setup(){
  left.setup(5);
  right.setup(6);
  lidar.setup();
  odom.setup();
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
      left.set(50);
      right.set(50);
      break;
    case DriveDirection::LEFT:
      left.set(50);
      right.set(-50);
      break;
    case DriveDirection::RIGHT:
      left.set(-50);
      right.set(50);
      break;
    case DriveDirection::BACKWARD:
      left.set(-50);
      right.set(-50);
      break;
  }
}

void Robot::stopDrive(){
    left.set(0);
    right.set(0);
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
            stopDrive();
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
  int power = 0;
  double kP = .5;
  if (abs(angle < 5)){
    left.set(0);
    right.set(0);
    return true;
  }
  else if (angle > 180){
    power = (360-angle)*kP;
    left.set(power);
    right.set(power);
  }
  else {
    power = (360-angle)*kP;
    left.set(-power);
    right.set(-power);
  }
  return false;

}

void Robot::driveAndAvoid(){
  DriveDirection dir = searcher.getDirection();
  setDrive(dir);
  drive();
}

