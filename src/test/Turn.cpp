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
  if (!digitalRead(29) && !turning){
    direction = base.dir() + M_PI/4;
    turning = true;
    debugPrint(0,"setpoint=%d",(int)(direction*M_PI/180));
  }


  if (turning){
    if (base.turnAbsolutely(direction)){
      turning = false;
    }
  }
}
