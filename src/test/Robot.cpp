#include "Robot.hpp"
#include "../main.hpp"
#include "Arduino.h"

Robot *Robot::instance = NULL;

Robot::Robot() {}

void Robot::setup(){
  lidar.setup();
  base.setup();
  ff.setup();
  searcher.setup();
  extinguisher.setup();
  pinMode(29,INPUT_PULLUP);
}

Robot *Robot::getInstance(){
  if(instance == NULL){
    instance = new Robot();
  }
  return instance;

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

void Robot::pushPos(){
  path.push(Point<float>(base.x(),base.y()));
}

void Robot::setGoalToCandle(){
  int distanceToCandleInches = Robot::getInstance()->detector.distance() / 25.4;
  int oneMeterBeforeCandleInches = distanceToCandleInches - 40;
  Point<float> delta(oneMeterBeforeCandleInches, 0);

  float ang = base.dir()*M_PI/180;
  delta = delta.rotate(ang);

  debugPrint(1, "dX=%4d dY=%4d", (int)delta.x(), (int)delta.y());
  Point<float> goalPoint = base.odom.robotToWorld(delta);
  navigator.setGoal(goalPoint);
}

void Robot::setGoalInRobotFrame(Point<float> delta){
  float ang = detector.angle()*M_PI/180;
  delta = delta.rotate(ang);

  debugPrint(1, "dX=%4d dY=%4d", (int)delta.x(), (int)delta.y());
  Point<float> goalPoint = base.odom.robotToWorld(delta);
  navigator.setGoal(goalPoint);
}

bool Robot::search(){
  return searcher.run();
}

bool Robot::findCandleHeight(){

  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;
    stop();
    base.drive();
  }

  if(!scanning){
    ff.startScan();
    scanning = true;
  }

  int candleHeight_mm = ff.watch(detector.distance());

  if(candleHeight_mm > 0){
    return true;
  }
  else if (candleHeight_mm == 0){
    return false;
  }
  else { // on candle at all
    scanning = false;
    return false;
  }
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
