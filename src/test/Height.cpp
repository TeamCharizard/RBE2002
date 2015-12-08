#include "Height.hpp"
#include "Arduino.h"

long t0;
const int BUTTON_PIN = 29;

void Height::setup(){
  t0 = millis();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ff.setup();
}

void Height::loop(){
  if (!digitalRead(BUTTON_PIN)){
    ff.startScan();
  }

  int height = ff.watch(30);

  if (height > 0){
    Serial.print("HEIGHT = ");
    Serial.println(height);
  }

}
