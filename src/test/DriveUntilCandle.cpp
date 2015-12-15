#include "DriveUntilCandle.hpp"
#include "../charizard.hpp"
#include <math.h>

void DriveUntilCandle::setup(){
  lidar.setup();
  base.setup();
  pinMode(29,INPUT_PULLUP);
}

void DriveUntilCandle::avoidInFront(int distance){
  if (distance < 500 && distance > 0){
    base.setSpeeds(-100,100);
  }
  else {
    base.setSpeeds(100,100);
  }
}

void DriveUntilCandle::loop(){

  bool fullSweep = lidar.read();

  if (fullSweep){
    debugPrint(1,"full sweep");
    base.drive();
    distances = lidar.distances;

    if (digitalRead(29)){
      avoidInFront(distances[0]);
      char msg[16];
      snprintf(msg,16,"d0=%-5d", distances[0]);
      Display.setCursor(0,1);
      Display.print(msg);
    }
    else {
      base.stop();
    }

    if (cd.detect()){
      count++;

      // Only stop and report that a candle is found once
      // the candle has been detected multiple times.
      // (otherwise sometimes I think the robot will detect it,
      // stop, jerk back a bit and no longer detect the candle)
      char msg[16];
      snprintf(msg,16,"a=%-3d d=%-4d", cd.angle(), cd.distance());
      Display.setCursor(0,0);
      Display.print(msg);
      Serial.println(msg);
    }
    else {
      Display.setCursor(0,0);
      Display.print("a=    d=    ");
    }
  }
}
