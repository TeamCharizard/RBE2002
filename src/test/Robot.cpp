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
      if(angleToCandle > 180) angleToCandle -= 360;
      startAngle = base.dir();
      debugPrint(1,"sa=%+3d",(int)(startAngle*180/M_PI));
      return true;
    }

  }
  return false;
}

bool Robot::driveToCandle(){
  double angleTurned = -(base.dir()-startAngle);
  debugPrint(1, "at=%+3d, ac=%+3d", (int)(angleTurned*180/M_PI), angleToCandle);
  if(turnToFace(angleToCandle-angleTurned*180/M_PI)) {
    stop();
    return false;
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
  return extinguisher.run();
}

bool Robot::returnToOrigin(){
  return false;
}

bool  Robot::turnToFace(double angle){
  //turn so that angle will become zero
  //if angle is within 5 degrees, end
  //this is really dumb and should be fixed
  double kP = .05;
  //int power = max(-10, min(10, (int)(kP*angle)));
  int power = kP*angle;
  if(power > 10) power = 10;
  if(power < -10) power = -10;
  debugPrint(1, "a=%+3d p=%+2d %+2d", (int)angle, power, -power);
  base.setSpeeds(power,-power);
  if(digitalRead(29)){
    base.run();
  }
  /*
  if(angle < 2) {
      stop();
      return true;
  }
  */
  /*
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
  */
  //drive();
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

