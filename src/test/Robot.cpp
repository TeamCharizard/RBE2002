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
      //debugPrint(1,"FORWARD");
      base.setSpeeds(10,10);
      break;
    case DriveDirection::LEFT:
      //debugPrint(1,"LEFT");
      base.setSpeeds(-10,10);
      break;
    case DriveDirection::RIGHT:
      //debugPrint(1,"RIGHT");
      base.setSpeeds(10,-10);
      break;
    case DriveDirection::BACKWARD:
      //debugPrint(1,"BACKWARD");
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
      debugPrint(1,"FORWARD");
      break;
    case DriveDirection::LEFT:
      debugPrint(1,"LEFT");
      break;
    case DriveDirection::RIGHT:
      debugPrint(1,"RIGHT");
      break;
    case DriveDirection::BACKWARD:
      debugPrint(1,"BACKWARD");
      break;

  }
}

bool Robot::search(){
  bool fullSweep = lidar.read();

  if (fullSweep){
    //debugPrint(1,"full sweep");
    driveAndAvoid();
    bool candleFound = detector.detect(&distanceToCandle, &angleToCandle, distances);

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
    /*
    power = (360-angle)*kP;
    if(power>10){
        power = 10;
    }
    base.setSpeeds(power,-power);
    */
    setDrive(DriveDirection::LEFT);
  }
  else {
      /*
    power = (360-angle)*kP;
    if(power > 10){
        power = 10;
    }
    base.setSpeeds(-power,power);
    */
    setDrive(DriveDirection::RIGHT);
  }
  drive();
  return false;

}

void Robot::driveAndAvoid(){
  //DriveDirection dir = searcher.getDirection();
   
  if (distances[0]  < 500 && distances[0] > 0){
    if (distances[350] > distances[10] && driveDirection != DriveDirection::LEFT){
        setDrive(DriveDirection::LEFT);
    }
    else if (driveDirection != DriveDirection::RIGHT){
        setDrive(DriveDirection::RIGHT);
    } 
  }
  else if(driveDirection != DriveDirection::FORWARD){
        setDrive(DriveDirection::FORWARD);
  }
  drive();
}

