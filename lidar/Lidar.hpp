#pragma once

#include "mraa.hpp"

typedef char BYTE;

class Lidar {


  public:
    int distances[360];

    Lidar();

    bool read();

    void processEndOfPacket();

    bool isDataIndex(int index);

  private:
    int packet[22];

    bool startReading;

    int packetNumber,
        packetIndex,
        distanceIndex;

    mraa::Uart dev;

};
