#include "Search.hpp"
#include "Arduino.h"

Search::Search() :  left(0,0,0),
  right(0,0,0){}

void Search::setup(){
  left.setup(9);
  right.setup(8);
  left.set(100);
  right.set(-100);
  lidar.setup();
}

void Search::loop(){
  fullSweep = lidar.read();

  if (fullSweep){
    Serial.println("Full");
    distances = lidar.distances;
    dFront = distances[0];
    dRight = distances[10];
    dLeft = distances[350];
    Display.setCursor(1,1);
    char str[18];
    sprintf(str, "l=%d, f=%d, r=%d", dLeft, dFront, dRight);
    Display.print(str);
    Serial.println(str);
  }

  long now = millis();
  long t = now - lastMotorLoop;
  if(t > 50) {
      lastMotorLoop = now;
      if (dFront < 500 && dFront > 0 && !turning){
        last_update = now;
        turning = true;
        if (dRight > dLeft){
          left.set(-100);
          right.set(-100);
        }
        else {
          left.set(100);
          right.set(100);
        }
      }

      if (turning){
        long timestep = now - last_update;
        if (timestep > 2000){
          turning = false;
          left.set(100);
          right.set(-100);
          last_update = now;
        }
      }
  }
}
