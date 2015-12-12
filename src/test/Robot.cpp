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
  else{
    stop();
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
  bool fullSweep = lidar.read();

  if (fullSweep){
    driveAndAvoid();
    bool candleFound = detector.detect(&distanceToCandle, &angleToCandle, lidar.distances);

    if (candleFound){
      old_base_dir = base.dir();
      debugPrint(1,"a=%-3d d=%-4d", angleToCandle, distanceToCandle);
      return true;
    }

  }
  return false;
}

bool Robot::driveToCandle(){
  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;
    if(turnToFaceAbsolutely(old_base_dir+angleToCandle * M_PI / 180)) {
      stop();
      return false;
    }
  }
  return false;
}

bool Robot::findCandleHeight(){
  if(!scanning){
    ff.startScan();
    scanning = true;
  }
  candleHeight_mm = ff.watch(distanceToCandle);
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

void Robot::driveAndAvoid(){
  if (lidar.distances[0]  < 500 && lidar.distances[0] > 0){
    if (lidar.distances[350] > lidar.distances[100]){
      setDrive(DriveDirection::LEFT);
    }
    else{
      setDrive(DriveDirection::RIGHT);
    }
  }
  else if (lidar.distances[0] > 0){
    setDrive(DriveDirection::FORWARD);
  }
  base.drive();
}

