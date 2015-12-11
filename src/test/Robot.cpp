#include "Robot.hpp"
#include "../main.hpp"
#include "Arduino.h"

Robot *Robot::instance = NULL;

Robot::Robot() {}

void Robot::setup(){
  lidar.setup();
  base.setup();
  ff.setup();
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
  if(digitalRead(29)){
    base.run();
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

bool Robot::search(){
  bool fullSweep = lidar.read();

  if (fullSweep){
    driveAndAvoid();
    bool candleFound = detector.detect(&distanceToCandle, &angleToCandle, lidar.distances);

    if (candleFound){
      debugPrint(1,"a=%-3d d=%-4d", angleToCandle, distanceToCandle);
      return true;
    }

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
  double kP = .05;
  if (abs(angle < 5)){
    stop();
    return true;
  }
  else if (angle > 180){
    setDrive(DriveDirection::LEFT);
  }
  else {
    setDrive(DriveDirection::RIGHT);
  }
  drive();
  return false;

}

void Robot::driveAndAvoid(){
  if (lidar.distances[0]  < 500 && lidar.distances[0] > 0){
    if (lidar.distances[350] > lidar.distances[10]){
      setDrive(DriveDirection::LEFT);
    }
    else{
      setDrive(DriveDirection::RIGHT);
    }
  }
  else if (lidar.distances[0] > 0){
    setDrive(DriveDirection::FORWARD);
  }
  base.run();
}

