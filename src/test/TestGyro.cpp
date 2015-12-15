#include "TestGyro.hpp"

void TestGyro::setup(){
  gyro.setup();
}

void TestGyro::loop(){
  float angle = gyro.read();
  Serial.println(angle);
  delay(100);
}
