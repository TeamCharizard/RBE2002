#include "Turn.hpp"
#include "Arduino.h"
#include "../charizard.hpp"
#include "../Robot.hpp"

void Turn::setup(){
  pinMode(29,INPUT_PULLUP);
  Robot::getInstance()->setup();
  direction = 0;
}

void Turn::loop(){
  if (!digitalRead(29)){
    direction = random(360) * M_PI / 180;
    debugPrint(0,"setpoint=%d",(int)(direction * 180 / M_PI));
    debugPrint(1,"turn.");
  }

  long now = millis();
  if (now - lastUpdateTime > 50){
    lastUpdateTime = now;
    if (Robot::getInstance()->turnToFaceAbsolutely(direction)){
      debugPrint(1,"done!");
    }
  }
}
