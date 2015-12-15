#include "Fan.hpp"
#include "Arduino.h"

void Fan::setup(){
  
    
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  motor.attach(11,1000,2000);
  motor.write(180);
  while(digitalRead(BUTTON_PIN));
  while(!digitalRead(BUTTON_PIN));
    //wait for button press and release
  motor.write(0);
}

void Fan::spin(){
  motor.write(180);
}

void Fan::stop(){
  motor.write(0);
}
