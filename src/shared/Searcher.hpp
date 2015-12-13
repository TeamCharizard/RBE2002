#pragma once

#include "DriveMotor.hpp"
#include "Lidar.hpp"

class Searcher {
  private:
    enum CheckState {
      THINKING,
      FOUND,
      MISTAKEN,
    };

  public:
    Searcher();

    DriveDirection getDirection();
    DriveDirection driveAndAvoid();

    CheckState check();
    bool search();
    bool turnToFaceCandle();
    bool driveToCandle();

    bool run();
    int sampleAt(int i, int ss = 10);

  private:

    enum State {
      SEARCHING,
      TURNING,
      CHECKING,
      TURN_TO_CANDLE,
      DRIVE_TO_CANDLE,
      CHECK_FINAL,
      TURN_TO_CANDLE_FINAL,
    };

    const char *stateNames[7] = {
        "SEARCH    ",
        "TURNING   ",
        "CHECKING  ",
        "TURNING   ",
        "DRV_2_CNDL",
        "CHK_FINAL ",
        "TURN_FINAL"};

    State state;
    long lastUpdateTime = 0;
    float dirAtStartOfTurn = 0;
    float goalDir;
    int candleCount = 0,
        sweeps = 0;

    const static long UPDATE_PERIOD = 50;
    const static int AVOID_DISTANCE = 400;
};
