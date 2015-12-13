#include "LidarBenchmark.hpp"

bool on;
int i=0;

void LidarBenchmark::setup(){
  lidar.setup();
  t0 = millis();
  pinMode(13,OUTPUT);
}

void LidarBenchmark::loop(){
  bool fullSweep = lidar.read();

  if (fullSweep){
    char msg[17];
    snprintf(msg, 17, "miss=%-2u invld=%-2d", lidar.misses, lidar.invalids);
    Display.setCursor(0,0);
    Display.print(msg);

    on = !on;

    digitalWrite(13,on);
    //delayMicroseconds(200);
  }
}
