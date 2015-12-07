#include "Search.hpp"
#include "Arduino.h"

DriveDirection Searcher::getDirection(){
  fullSweep = lidar.read();

  if (fullSweep){
    distances = lidar.distances;
    dFront = distances[0];
    dRight = distances[10];
    dLeft = distances[350];
  }

  if (dFront < 500 && dFront > 0 && !turning){
    last_update = now;
    turning = true;
    if (dRight > dLeft){
      return DriveDirection::RIGHT;
    }
    else {
      return DriveDirection::LEFT;
    }
  }

  if (turning){
    long timestep = millis() - last_update;
    if (timestep > 2000){
      turning = false;
      return DriveDirection::FORWARD;
    }
  }
}
