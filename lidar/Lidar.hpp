#pragma once

#include "mraa.hpp"

typedef char BYTE;

class Lidar {

  int distances[360];
  int packet[22];

  bool startReading;

  int packetNumber,
      packetIndex,
      distanceIndex;

  mraa::Uart dev;

  public:
    Lidar();

    bool read();

    void processEndOfPacket();

    bool isDataIndex(int index);

};
