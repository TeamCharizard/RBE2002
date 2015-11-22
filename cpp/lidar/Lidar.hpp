#pragma once

#include "mraa.hpp"

class Lidar {

  public:
    int distances[360];

    Lidar();

    bool read();

    void processEndOfPacket();

    bool isDataIndex(int index);

  private:
    char packet[22];

    bool startReading;

    int packetNumber,
        packetIndex,
        distanceIndex;

    mraa::Uart dev;

};
