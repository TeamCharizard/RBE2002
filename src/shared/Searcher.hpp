#pragma once

#include "DriveMotor.hpp"
#include "Lidar.hpp"

class Searcher {
  public:
    Searcher();

    DriveDirection getDirection();
    DriveDirection driveAndAvoid();

    bool check();
    bool search();
    bool turnToFaceCandle();
    bool driveToCandle();

    bool run();
    int sampleAt(int *distances, int i);

  private:

    enum State {
      SEARCHING,
      TURNING,
      CHECKING,
      TURN_TO_CANDLE,
      DRIVE_TO_CANDLE,
    };

    const char *stateNames[5] = {
        "SEARCH    ",
        "TURNING   ",
        "CHECKING  ",
        "TURNING   ",
        "DRV_2_CNDL"};

    State state;
    long lastUpdateTime = 0;
    float dirAtStartOfTurn = 0;
    float goalDir;
    int candleCount = 0,
        sweeps = 0;

    const static long UPDATE_PERIOD = 50;
};
