#include "test/PointToCandle.hpp"
#include "test/Search.hpp"
#include "test/Main.hpp"
#include "test/PrintOdom.hpp"
#include <Servo.h>

//driveUntilCandle sketch;
Search sketch;
//PrintOdom sketch;

void setup(){
  Serial.begin(9600);
  sketch.setup();
}

void loop(){
  sketch.loop();
}
