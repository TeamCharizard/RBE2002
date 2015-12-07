#pragma once

class Lidar {

  public:
    int distances[360];

    Lidar();

    void setup();

    bool read();

    void processEndOfPacket();

    bool isDataIndex(int index);

  private:
    char packet[22];

    bool startReading;

    int packetNumber,
        packetIndex,
        distanceIndex;
};
