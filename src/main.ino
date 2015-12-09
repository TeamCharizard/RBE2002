#include "main.hpp"

#include "test/PointToCandle.hpp"
#include "test/Search.hpp"
#include "test/Main.hpp"
#include "test/Height.hpp"
#include "test/PrintOdom.hpp"
#include "test/LidarBenchmark.hpp"

LiquidCrystal Display(40,41,42,43,44,45);

LidarBenchmark sketch;

void setup(){
  Display.begin(16,2);
  Serial.begin(9600);
  sketch.setup();
}

void loop(){
  sketch.loop();
}
