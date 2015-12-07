#include "Point.hpp"
#include <cmath>

void Point::turnToFace(int angle){
  //turn so that angle will become zero
  int power = 0;
  double kP = .5;
  if (std::abs(angle < 10)){
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

void Point::loop(){
  bool fullSweep = lidar.read();

  if (fullSweep){
    distances = lidar.distances;

    int candleLocation = 0;
    int candleDistance = 0;
    if(cd.detect(candleDistance, candleLocation, distances)) {
      //turn to face that angle
      turnToFace(candleLocation);
    }
  }
}
