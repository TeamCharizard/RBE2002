#include "PrintOdom.hpp"

void PrintOdom::setup(){
  odom.setup();
}

void PrintOdom::loop(){
  usleep(50000);
  odom.updateDifferential();
  auto pos = odom.getPos();
}
