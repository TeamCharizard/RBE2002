#include "Searcher.hpp"
#include "Arduino.h"
#include "../test/Robot.hpp"

DriveDirection Searcher::getDirection() {
  int *distances = Robot::getInstance()->lidar.distances;
  float direction = Robot::getInstance()->base.dir();
  dFront = distances[0];
  dRight = distances[10];
  dLeft = distances[350];

  if (dFront < 500 && dFront > 0 && !turning){
    turning = true;
    if (dRight > dLeft){
      return DriveDirection::RIGHT;
    }
    else {
      return DriveDirection::LEFT;
    }
  }

  if (turning){

    float turnAngle = direction - lastDirection;
    if (turnAngle > 1.57079633){
      turning = false;
      return DriveDirection::FORWARD;
    }
  }

  lastDirection = direction;
}
