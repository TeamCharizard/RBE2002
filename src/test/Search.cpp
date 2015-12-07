#include "Search.hpp"

void Search::setup(){
  left.setup();
  right.setup();
}

void Search::loop(){
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
      left.set(-50);
      right.set(-50);
    }
    else {
      left.set(50);
      right.set(50);
    }
  }

  if (turning){
    long timestep = millis() - last_update;
    if (timestep.count() > 2000){
      turning = false;
      left.set(-50);
      right.set(50);
    }
  }
}
