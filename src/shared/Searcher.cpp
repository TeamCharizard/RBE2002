#include "Searcher.hpp"
#include "Arduino.h"

DriveDirection Searcher::getDirection(float direction, int *distances){
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
