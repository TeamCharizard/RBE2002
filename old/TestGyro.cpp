#include "TestGyro.hpp"

void TestGyro::setup(){
  gyro.setup();
}

void TestGyro::loop(){
  int angle = gyro.read();
}
