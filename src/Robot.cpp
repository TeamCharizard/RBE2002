#include "Robot.hpp"
#include "shared/StatusManager.hpp"
#include "charizard.hpp"
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
  pushPos();
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

void Robot::hardStop(){
  base.stop();
  base.hardStop();
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
  int distanceToCandleInches = detector.distance() / 25.4;
  int oneMeterBeforeCandleInches = distanceToCandleInches - CANDLE_APPROACH_DISTANCE_INCHES;
  Point<float> delta(oneMeterBeforeCandleInches, 0);

  setGoalInCandleFrame(delta);
}

void Robot::setGoalInCandleFrame(Point<float> delta){
  float ang = detector.angle()*M_PI/180;
  delta = delta.rotate(ang);

  Point<float> goalPoint = base.odom.robotToWorld(delta);
  navigator.setGoal(goalPoint);
}

float Robot::absoluteCandleAngleFromCurrentPosition(){
  return base.dir() + detector.angle() * M_PI / 180;
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

  float candleHeight = ff.watch(detector.distance());

  if(candleHeight > 0){
    if (candleHeight > 11){
      candleHeight = 11;
    }
    else if (candleHeight < 6.5){
      candleHeight = 6.5;
    }
    StatusManager::candleHeight = (int)(candleHeight + 0.5);
    StatusManager::candleHeightFrac = (int)(candleHeight * 10) % 10;

    return true;
  }
  else if (candleHeight == 0){
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

void Robot::popWaypoint(){
  waypoint = path.pop();
  navigator.setGoal(waypoint);
  Serial.print("wpt=(");
  Serial.print(waypoint.x());
  Serial.print(", ");
  Serial.println(waypoint.y());
  Serial.print(")");
}

bool Robot::returnToOrigin(){
  long now = millis();
  if (now - lastUpdateTime > UPDATE_PERIOD){
    lastUpdateTime = now;

    if (navigator.run()){
      if (path.empty()){
        return true;
      }
      else {
        popWaypoint();
      }
    }
  }
  return false;
}

void Robot::setFinalAbsoluteCandlePosition(){
  Point<float> position = base.odom.robotToWorld(detector.relativePosition());
  StatusManager::candleX = position.x();
  StatusManager::candleY = position.y();
}

bool Robot::turnToFaceAbsolutely(float angle){
  return base.turnAbsolutely(angle);
}

void Robot::end(){
  hardStop();
  StatusManager::finalUpdate();
}
