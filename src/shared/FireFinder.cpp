#include "FireFinder.hpp"
#include <math.h>
#include <stdio.h>

FireFinder::FireFinder() {
  //head.period_ms(20);
  //head.pulsewidth_us(1500);
  //head.enable(true);
}

bool FireFinder::checkHeightInFront(int distanceToCandle){
    // TODO: make this work
    /*
  //move the head from low to hi
  int lowP = 500, highP = 2300;
  int minVal = 1024;
  int minPulse = highP;
  for (int i=lowP;i<highP;i++){
    //head.pulsewidth_us(i);
    head.write

    int intensity = analogRead(SENSOR_PIN);

    if (intensity < minVal){
      minVal = intensity;
      minPulse = i;
      printf("%d %d\n",minVal, minPulse);
    }

    usleep(1000);
  }

  head.pulsewidth_us(minPulse);
  int angle = ((minPulse - lowP) * MAX_HEAD_ANGLE) / (highP - lowP) + -MIN_HEAD_ANGLE;
  int height = SENSOR_HEIGHT + tan(angle*3.14159265/180.0) * distanceToCandle;
  printf("%d %d %d %d\n", minVal, minPulse, angle, height);

  return false;
  */
}
