#include <Arduino.h>
#include "Lidar.hpp"

Lidar::Lidar() :
    packetNumber(0),
    packetIndex(0),
    distanceIndex(0),
    startReading(false) {}

void Lidar::setup() {}

bool Lidar::read(){
  if (Serial1.available()) {
    char b = Serial1.read();

    if (startReading) {
      if (packetIndex == 21) {
        startReading = false;
        processEndOfPacket();

        return distanceIndex >= 359;
      }
      else {
        packet[packetIndex] = b;
        packetIndex++;
      }
    }

    if (!startReading && (b == (char) 0xfa)){
      startReading = true;
      packetIndex = 0;
      packet[packetIndex] = b;
      packetIndex++;
      return false;
    }
  }
}

void Lidar::processEndOfPacket(){
  int newPacketNumber = packet[1];

  if ((newPacketNumber - packetNumber) == 1){
    for (int i=0; i < 22; i++){
      if (isDataIndex(i)){
        distanceIndex = (newPacketNumber - (char)0xA0) * 4 + i/4 - 1;

        //since lidar is 10 degrees off, we compensate here
        /*
        distanceIndex -= 10;

        if (distanceIndex < 0){
          distanceIndex = 360 + distanceIndex;
        }
        */

        if ((distanceIndex >= 0) && (distanceIndex < 360)){
          if ((packet[i+1] & (char)0x80) >> 7){
            distances[distanceIndex] = -1;
          }
          else {
            int d = (unsigned char)packet[i] | (packet[i+1] << 8);

            if (d <= 0 || d > 6000){
              d = -1;
            }

            distances[distanceIndex] = d;
          }
        }
      }
    }
  }

  packetNumber = newPacketNumber;

  if (packetNumber >= (char)0xF9){
    packetNumber = (char)0x9F;
  }
}

bool Lidar::isDataIndex(int index){
  return index == 4 || index == 8 || index == 12 || index == 16;
}
