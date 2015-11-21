#include "lidar.hpp"
#include "stdio.h"
#include "iostream"

Lidar::Lidar() try : dev(0),
    packetNumber(0),
    packetIndex(0),
    distanceIndex(0),
    startReading(false) {

  if (dev.setBaudRate(115200) != mraa::SUCCESS) {
       std::cout << "Error setting parity on UART" << std::endl;
   }
   if (dev.setMode(8, mraa::UART_PARITY_NONE, 1) != mraa::SUCCESS) {
       std::cout << "Error setting parity on UART" << std::endl;
   }
   if (dev.setFlowcontrol(false, false) != mraa::SUCCESS) {
       std::cout << "Error setting flow control UART" << std::endl;
   }
}
  catch (std::exception) {
    std::cout << "Error initialize uart" << std::endl;
    std::terminate();
}

bool Lidar::read(){
  if (dev.dataAvailable()) {
    char b;
    int read = dev.read(&b, 1);

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
        if ((distanceIndex >= 0) && (distanceIndex < 360)){
          if ((packet[i+1] & (char)0x80) >> 7){
            distances[distanceIndex] = 0;
          }
          else {
            int d = packet[i] | ((packet[i+1] & (char)0x3f) << 8);

            if (d < 0 || d > 6000){
              d = 0;
            }

            distances[distanceIndex] = d;
            printf("%d, %d\n", distanceIndex, d);
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

int main(int argc, char **argv){
  Lidar lidar;
  while (true) {
    lidar.read();
  }
}
