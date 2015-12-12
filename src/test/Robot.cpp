#include "Robot.hpp"
#include "../main.hpp"
#include "Arduino.h"

Robot *Robot::instance = NULL;

Robot::Robot() {}

void Robot::setup(){
  lidar.setup();
  base.setup();
  ff.setup();
  extinguisher.setup();
  pinMode(29,INPUT_PULLUP);
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
      base.setSpeeds(100,100);
      break;
    case DriveDirection::LEFT:
      base.setSpeeds(-100,100);
      break;
    case DriveDirection::RIGHT:
      base.setSpeeds(100,-100);
      break;
    case DriveDirection::BACKWARD:
      base.setSpeeds(-100,-100);
      break;
  }
}

void Robot::stop(){
  base.stop();
}

void Robot::setDrive(DriveDirection dir){
  this->driveDirection = dir;

  switch (this->driveDirection){
    case DriveDirection::FORWARD:
      base.setSpeeds(100,100);
      break;
    case DriveDirection::LEFT:
      base.setSpeeds(-100,100);
      break;
    case DriveDirection::RIGHT:
      base.setSpeeds(100,-100);
      break;
    case DriveDirection::BACKWARD:
      base.setSpeeds(-100,-100);
      break;
  }
}

bool Robot::search(){
  return searcher.run();
}

bool Robot::findCandleHeight(){
  if(!scanning){
    ff.startScan();
    scanning = true;
  }
  candleHeight_mm = ff.watch(detector.distance());
  if(candleHeight_mm > 0){
    return true;
  }
  return false;
}

bool Robot::extinguishCandle(){
  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;
    return extinguisher.run();
  }
  return false;
}

bool Robot::returnToOrigin(){
  return false;
}

bool Robot::turnToFaceAbsolutely(float angle){
  return base.turnAbsolutely(angle);
}
