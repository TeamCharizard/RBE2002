#include "CandleDetector.hpp"
#include <cmath>

CandleDetector::CandleDetector(){}

int CandleDetector::detect(int radii[]){
  int lastRadius,
      dRadius = 0,
      widthBetweenSpikes = 0,
      lastSpikeAngle = 0;

  for (int angle=0;angle<360;angle++){
    int radius = radii[angle];

    //ignore obviously invalid data
    //80mm is within the robot
    if (radius > 80) {

      dRadius =  lastRadius - radius;

      //spikes on the rising edge
      if (dRadius > MIN_SPIKE && dRadius < MAX_SPIKE){
        lastSpikeAngle = angle;
      }
      //spikes on the falling edge
      if (dRadius < -MIN_SPIKE && dRadius > -MAX_SPIKE){
        widthBetweenSpikes = lastSpikeAngle - angle;

        if (std::abs(widthBetweenSpikes - WIDTH) < WIDTH_TOLERANCE){
          return angle + widthBetweenSpikes/2;
        }
      }
    }
    lastRadius = radius;
  }

  return 0;
}
