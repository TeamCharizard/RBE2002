#include "CandleDetector.hpp"
#include <stdio.h>
#include <cmath>

CandleDetector::CandleDetector(){}

int CandleDetector::detect(int radii[]){
  int lastRadius,
      dRadius = 0,
      aBetweenSpikes = 0,
      lastSpikeA = 0;

  //in the event that we are facing the candle...
  // the values could be split across 0 degress
  // to fix this, we wrap around by 20 degrees.
  for (int a=-20;a<360;a++){
    int angle = a;
    if (a<0) angle = 360 + a;

    int radius = radii[angle];

    //ignore obviously invalid data
    //80mm is within the robot
    if (radius > 80) {

      dRadius = lastRadius - radius;

      //spikes on the rising edge
      if (dRadius > MIN_SPIKE && dRadius < MAX_SPIKE){
        //we use "a" here because we want +10 and +355 to be 15deg apart
        lastSpikeA = a;
      }
      //spikes on the falling edge
      if (dRadius < -MIN_SPIKE && dRadius > -MAX_SPIKE){
        //calculate the distance between the points
        aBetweenSpikes = std::abs(lastSpikeA - a);
        int c = sqrt(radius*radius + lastRadius*lastRadius -
            2*radius*lastRadius*cos(aBetweenSpikes));
        printf("%d\n",c);


        if (std::abs(c - WIDTH) < WIDTH_TOLERANCE){
          return angle + aBetweenSpikes/2;
        }
      }
      lastRadius = radius;
    }
  }

  return 0;
}
