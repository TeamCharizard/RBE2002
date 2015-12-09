#pragma once

class Lidar {

  public:
    int distances[360];

    /** the number of missed packets during each sweep */
    int misses;
    int m1,m2;

    /** the number of invalids during each sweep */
    int invalids;

    void setup();

    bool read();

    void processEndOfPacket();

    bool isDataIndex(int index);

  private:
    char packet[22];

    bool startReading;

    int packetIndex,
        distanceIndex;

    int packetNumber;
};
