#include "Height.hpp"
#include "Arduino.h"

void Height::setup(){
  ff.setup();
}

void Height::loop(){
  ff.checkHeightInFront(30);
  delay(500);
}
