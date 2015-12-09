#include <Arduino.h>
#include "CandleDetector.hpp"
#include <stdio.h>
#include <math.h>

CandleDetector::CandleDetector(){}

bool CandleDetector::detect(int *distanceOut, int *angleOut, int radii[]){
  int lastRadius,
      dRadius = 0,
      lastSpikeRad = 0,
      lastSpikeA = 0;

  //in the event that we are facing the candle...
  // the values could be split across 0 degress
  // to fix this, we wrap around by 20 degrees.
  for (int a=-20;a<360;a++){
    int angle = a;
    if (a<0) angle = 360 + a;

    int radius = radii[angle];

    //ignore obviously invalid data
    //120mm is within the robot
    if (radius > 120) {

      dRadius = lastRadius - radius;

      //spikes on the rising edge
      if (dRadius > MIN_SPIKE && dRadius < MAX_SPIKE){
        //we use "a" here because we want +10 and +355 to be 15deg apart
        lastSpikeA = a;
        lastSpikeRad = radius;
      }
      //spikes on the falling edge
      if (dRadius < -MIN_SPIKE && dRadius > -MAX_SPIKE){
        //calculate the distance between the points
        int angleBetweenSpikes = abs(lastSpikeA - a);
        double angleInRadians = angleBetweenSpikes*3.1415926535/180.0;
        int c = sqrt(lastRadius*lastRadius + lastSpikeRad*lastSpikeRad -
            2*lastRadius*lastSpikeRad*cos(angleInRadians));

        int midAngle = angle - angleBetweenSpikes/2;
        int midRadius = (lastRadius + lastSpikeRad)/2;

        if (abs(c - WIDTH) < WIDTH_TOLERANCE){
          printf("candle at %ddeg and %dmm away\n",midAngle,midRadius);
          *distanceOut = midRadius;
          *angleOut = midAngle;
          return true;
        }
      }
      lastRadius = radius;
    }
  }

  return false;
}
