#include <Arduino.h>
#include "Lidar.hpp"

void Lidar::setup() {
    Serial2.begin(115200);
    packetNumber = 0;
    packetIndex = 0;
    distanceIndex = 0;
    startReading = false;
    memset(distances, -1, 360*sizeof(int));
    // Make sure we've tried to read a full sweep
    // before doing anything
    while(!read());
}

bool Lidar::read(){
  if (Serial2.available()) {
    char b = Serial2.read();

    if (startReading) {
      if (packetIndex == 21) {
        startReading = false;
        processEndOfPacket();

        if (distanceIndex >= 357){
          return true;
        }
        return false;
      }
      else {
        packet[packetIndex] = b;
        packetIndex++;
      }
    }

    if (!startReading && (b == (char) 0xfa)){
      if (distanceIndex >= 357){
        memset(distances, -1, 360*sizeof(int));
        /*
        Serial.print("misses: ");
        Serial.print(misses);
        Serial.print(" inv: ");
        Serial.println(invalids);
        */
        misses = 0;
        invalids = 0;
      }
      startReading = true;
      packetIndex = 0;
      packet[packetIndex] = b;
      packetIndex++;
    }
  }
  return false;
}

void Lidar::processEndOfPacket(){
  int newPacketNumber = packet[1];

  if ((newPacketNumber - packetNumber) == 1){
    for (int i=0; i < 22; i++){
      if (isDataIndex(i)){
        distanceIndex = (newPacketNumber - (char)0xA0) * 4 + i/4 - 1;

        if ((distanceIndex >= 0) && (distanceIndex < 360)){
          if ((packet[i+1] & (char)0x80) >> 7){
            distances[distanceIndex] = -1;
            invalids++;
          }
          else {
            int d = (unsigned char)packet[i] | (packet[i+1] << 8);

            if (d <= 140 || d > 6000){
              invalids++;
              d = -1;
            }

            distances[distanceIndex] = d;
          }
        }
      }
    }
  }
  else {
    misses++;
  }

  packetNumber = newPacketNumber;

  if (packetNumber >= (char)0xF9){
    packetNumber = (char)0x9F;
  }
}

bool Lidar::isDataIndex(int index){
  return index == 4 || index == 8 || index == 12 || index == 16;
}

