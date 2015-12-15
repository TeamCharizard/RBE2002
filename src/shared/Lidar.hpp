#pragma once

/** \brief Handles parsing and storage of lidar data.
 * Calling read will try to read a byte of data from Serial3.
 * THIS MUST BE CALLED WITHIN EVERY 100uS.
 * If you call it any slower it will start missing data.
 * The proper way to do this is call read continuously,
 * and wait for it to return true. When it returns true you know a
 * full sweep of lidar has passed, and then you can
 * update motors and do print statements and stuck.
 */
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
