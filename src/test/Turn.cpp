#include "Turn.hpp"
#include "Arduino.h"
#include "../main.hpp"

void Turn::setup(){
  pinMode(29,INPUT_PULLUP);
  base.setup();
  turning = false;
  direction = 0;
}

void Turn::loop(){
  delay(200);
  if (!digitalRead(29) && !turning){
    direction = base.dir() + M_PI/4;
    turning = true;
  }

  if (turning){
    bool done = base.turnAbsolutely(direction);
    if (done){
      base.stop();
      turning = false;
    }
  }
  else {
    base.drive();
  }
}
