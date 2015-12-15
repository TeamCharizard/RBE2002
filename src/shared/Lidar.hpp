#pragma once

class Lidar {

  public:
    /**
     * \brief Array of distances from the lidar
     */
    int distances[360];

    /** the number of missed packets during each sweep */
    int misses = 0;

    /** the number of invalids during each sweep */
    int invalids;

    /**
     * \brief Setup the lidar
     */
    void setup();

    /**
     * \brief Read some data from the lidar
     * \return true if the lidar has just finished a full sweep
     */
    bool read();

  private:
    void processEndOfPacket();

    bool isDataIndex(int index);

    char packet[22];

    bool startReading;

    int packetIndex,
        distanceIndex;

    int packetNumber;
};
