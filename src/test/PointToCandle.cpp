#include <Arduino.h>
#include "PointToCandle.hpp"

void PointToCandle::setup(){
  left.setup(5);
  right.setup(6);
  lidar.setup();
}

void PointToCandle::turnToFace(int angle){
  //turn so that angle will become zero
  int power = 0;
  double kP = .5;
  if (abs(angle < 10)){
    left.set(0);
    right.set(0);
  }
  else if (angle > 180){
    power = (360-angle)*kP;
    left.set(power);
    right.set(power);
  }
  else {
    power = (360-angle)*kP;
    left.set(-power);
    right.set(-power);
  }
}

void PointToCandle::loop(){
  bool fullSweep = lidar.read();

  if (fullSweep){
    distances = lidar.distances;

    int *candleLocation;
    int *candleDistance;
    if(cd.detect(candleDistance, candleLocation, distances)) {
      //turn to face that angle
      turnToFace(*candleLocation);
    }
  }
}
