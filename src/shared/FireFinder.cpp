#include "FireFinder.hpp"
#include "../main.hpp"
#include "Arduino.h"
#include <stdio.h>

void FireFinder::setup() {
  head.attach(MOTOR_PIN);
}

bool FireFinder::seesCandle(){
  bool seesCandle;
  head.write(minPosition);
  long sum = 0;
  int ss = 20;
  for (int i = 0; i < ss; i++){
    sum += analogRead(SENSOR_PIN);
  }
  int intensity = sum/ss;
  seesCandle = (intensity < MIN_INTENSITY);
  return seesCandle;
}

void FireFinder::startScan(){
  scanning = true;
  position = 0;
  minIntensity = 1024;
  minPosition = 100;
  head.write(0);
}

int FireFinder::watch(int dToCandle){
  if (scanning){
    if (position > 180){
      head.write(0);

      scanning = false;
      position = 0;

      if (minIntensity > 1000){
        return -1;
      }

      float angle = (minPosition * (MAX_HEAD_ANGLE - MIN_HEAD_ANGLE) / 180) + MIN_HEAD_ANGLE;
      int height = SENSOR_HEIGHT + tan(angle * M_PI / 180.0) * dToCandle;
      heightInInches = height / 25.4;
      return heightInInches;
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
        if (intensity <  minIntensity){
          minIntensity = intensity;
          minPosition = position;
        }

      }
    }
  }
  return 0;
}
