#include <Arduino.h>
#include "CandleDetector.hpp"
#include <stdio.h>

CandleDetector::CandleDetector(){}

bool CandleDetector::detect(int *distanceOut, int *angleOut, int radii[]){
  double lastRadius = 0,
         lastA = 0,
      dRadius = 0,
      lastSpikeRad = 0,
      lastSpikeA = 0,
      lastSpikeAStart = 0;

  //in the event that we are facing the candle...
  // the values could be split across 0 degress
  // to fix this, we wrap around by 20 degrees.
  for (int a=-20;a<360;a++){
    int angle = a;
    if (a<0) angle = 360 + a;

    int radius = radii[angle];

    //ignore obviously invalid data
    //120mm is within the robot
    if (radius > 0) {

      dRadius = lastRadius - radius;

      //spikes on the rising edge
      if (dRadius > MIN_SPIKE && dRadius < MAX_SPIKE){
        //we use "a" here because we want +10 and +355 to be 15deg apart
        lastSpikeA = a;
        lastSpikeAStart = lastA;
        lastSpikeRad = radius;
      }
      //spikes on the falling edge
      if (dRadius < -MIN_SPIKE && dRadius > -MAX_SPIKE){
        //calculate the distance between the points
        int angleBetweenSpikes = abs(lastSpikeA - a);
        double angleInRadians = angleBetweenSpikes*3.1415926535/180.0;
        int c = sqrt(lastRadius * lastRadius +
            lastSpikeRad * lastSpikeRad -
            2.0 * lastRadius * lastSpikeRad * cos(angleInRadians));

        int midAngle = angle - angleBetweenSpikes/2;
        int midRadius = (lastRadius + lastSpikeRad)/2;

        if (abs(c - WIDTH) < WIDTH_TOLERANCE){

          int valid = 0;
          for (int i=lastSpikeAStart;i<=a;i++){
            int ang = i < 0 ? 360 + i : i;
            Serial.print(i);
            Serial.print(" ");
            Serial.println(radii[ang]);
            if(radii[ang] > 0) {
                valid++;
            }
          }

          float validPercent = (float)valid/(a-lastSpikeAStart+1);
          Serial.print("Percent valid: ");
          Serial.println(validPercent);

          *distanceOut = midRadius;
          *angleOut = midAngle;
          return true;
        }
      }
      lastRadius = radius;
      lastA = a;
    }
  }
  return false;
}
