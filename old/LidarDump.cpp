#include "LidarDump.hpp"

void LidarDump::setup() {
    charizard = Robot::getInstance();
    charizard->setup();
    reading = false;
    count = 0;
}

void LidarDump::loop() {
  if(reading) {
      bool fullSweep = charizard->lidar.read();

      if (fullSweep){
          count++;
          if(count > 1) {
              count = 0;
              reading = false;
              for(int i = 0; i < 360; i++) {
                  Serial.print("distances[");
                  Serial.print(i);
                  Serial.print("] = ");
                  Serial.println(charizard->lidar.distances[i]);
              }
          }
      }
  } else if (!digitalRead(29)) {
      reading = true;
  }
}
