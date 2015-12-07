#include "Robot.hpp"
#include "Arduino.h"

Robot *Robot::instance = NULL;

Robot::Robot() :
  left(0,0,0),
  right(0,0,0) {
}

void Robot::setup(){
  left.setup(5);
  right.setup(6);
  lidar.setup();
  odom.setup();
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

void Robot::setDrive(DriveDirection dir){
  this->driveDirection = dir;
}

bool Robot::search(){
  DriveDirection dir = searcher.getDirection();
  setDrive(dir);
  drive();
  return false;
}

bool Robot::driveToCandle(){
  return false;
}

bool Robot::findCandleHeight(){
  return false;
}

bool Robot::extinguishCandle(){
  return false;
}

bool Robot::returnToOrigin(){
  return false;
}
