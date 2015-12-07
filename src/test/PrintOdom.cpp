#include "PrintOdom.hpp"

void PrintOdom::setup(){

}

void PrintOdom::loop(){
  usleep(50000);
  odom.updateDifferential();
  auto pos = odom.getPos();
}
