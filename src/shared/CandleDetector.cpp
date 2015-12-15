#include <Arduino.h>
#include "CandleDetector.hpp"
#include "StatusManager.hpp"
#include <stdio.h>

const float CandleDetector::VALID_CANDLE_THRESHOLD = 0.8;

CandleDetector::CandleDetector(){}

int CandleDetector::angle(){
  return candleAngle;
}

int CandleDetector::distance(){
  return candleDistance;
}

Point<float> CandleDetector::relativePosition(){
  float relativeXInches = distance()*cos(angle()*M_PI/180)/25.4;
  float relativeYInches = distance()*sin(angle()*M_PI/180)/25.4;
  return Point<float>(relativeXInches, relativeYInches);
}

bool CandleDetector::detect(int radii[]){
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

        if (abs(c - WIDTH) < WIDTH_TOLERANCE &&
            abs(lastSpikeRad-lastRadius) < RADIUS_TOLERANCE){

          int valid = 0;
          for (int i=lastSpikeAStart;i<=a;i++){
            int ang = i < 0 ? 360 + i : i;
#if defined(DEBUG_LIDAR)
            Serial.print(i);
            Serial.print(" ");
            Serial.println(radii[ang]);
#endif
            if(radii[ang] > 0) {
                valid++;
            }
          }

          float validPercent = (float)valid/(a-lastSpikeAStart+1);
#if defined(DEBUG_LIDAR)
          Serial.print("Percent valid: ");
          Serial.print(validPercent);
          Serial.print(", a=");
          Serial.print(midAngle);
          Serial.print(", r=");
          Serial.println(midRadius);
#endif

          if (validPercent >= VALID_CANDLE_THRESHOLD){
            candleDistance = midRadius;
            candleAngle = midAngle;
            return true;
          }
        }
      }
      lastRadius = radius;
      lastA = a;
    }
  }
  return false;
}
