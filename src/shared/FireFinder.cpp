#include "FireFinder.hpp"
#include "Arduino.h"
//#include <math.h>
#include <stdio.h>

void FireFinder::setup() {
  head.attach(MOTOR_PIN);
}

void FireFinder::startScan(){
  scanning = true;
  position = 0;
  minIntensity = 1024;
  minPosition = 0;
  head.write(0);
}

int FireFinder::watch(int dToCandle){
  if (scanning){
    if (position > 180){
      head.write(0);
      if (minIntensity > 50){
        return -1;
      }

      scanning = false;
      position = 0;
      int angle = (minPosition * (MAX_HEAD_ANGLE - MIN_HEAD_ANGLE) / 180) + MIN_HEAD_ANGLE;
      Serial.println(angle);
      int height = SENSOR_HEIGHT + tan(angle*3.14159265/180.0) * dToCandle;
      Serial.println(height);
      return height;
    }
    else {
      long now = millis();
      if (now - timeToChangeAngle > sweepTime/(180/step)){
        head.write(position);
        position += step;
        timeToChangeAngle = now;

        long sum = 0;
        for (int i = 0; i < SAMPLE_SIZE; i++){
          sum += analogRead(SENSOR_PIN);
        }
        int intensity = sum / SAMPLE_SIZE;
        Serial.println(intensity);
        if (intensity <  minIntensity){
          minIntensity = intensity;
          minPosition = position;
        }

      }
    }
  }
  return 0;
}
