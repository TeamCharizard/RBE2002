#include "Robot.hpp"
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
  debugPrint(1, "X=%-3d Y=%-3d     ", (int)base.x(), (int)base.y());
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

float Robot::absoluteCandleAngle(){
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

  int candleHeight = ff.watch(detector.distance());

  if(candleHeight > 0){
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
  debugPrint(1, "cur=(%d,%d)", (int)base.pos().x(), (int)base.pos().y());
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

Point<float> Robot::absoluteCandlePosition(){
  return base.odom.robotToWorld(detector.position());
}

bool Robot::turnToFaceAbsolutely(float angle){
  return base.turnAbsolutely(angle);
}

void Robot::end(){
  Point<float> candle_pos = absoluteCandlePosition();
  stop();
  base.drive();
  debugPrint(0, "Pose=(%-3d,%-3d)", (int)(0.5 + candle_pos.x()), (int)(0.5 + candle_pos.y()));
  debugPrint(1, "Height=%-3d     ", (int)ff.heightInInches);
}
