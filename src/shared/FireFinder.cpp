#include "FireFinder.hpp"
#include "Arduino.h"
#include <math.h>
#include <stdio.h>

void FireFinder::setup() {
  head.attach(MOTOR_PIN);
}

void FireFinder::startScan(){
  scanning = true;
  position = 0;
}

int FireFinder::watch(int dToCandle){
  if (scanning){
    if (position > 180){
      scanning = false;
      position = 0;
      int angle = (minPosition * MAX_HEAD_ANGLE) / 180 + -MIN_HEAD_ANGLE;
      int height = SENSOR_HEIGHT + tan(angle*3.14159265/180.0) * dToCandle;
      return height;
    }
    else {
      head.write(position);
      int intensity = analogRead(SENSOR_PIN);

      if (intensity < minIntensity){
        minIntensity = intensity;
        minPosition = position;
      }
    }
  }
}
