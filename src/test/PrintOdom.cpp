#include "PrintOdom.hpp"

void PrintOdom::setup(){
  odom.setup();
}

void PrintOdom::loop(){
  delay(20);
  odom.updateDifferential();
  auto pos = odom.getPos();
}
