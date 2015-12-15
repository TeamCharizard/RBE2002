#pragma once

#include "Point.hpp"
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

    void setup();

    DriveDirection getDirection();
    DriveDirection driveAndAvoid();

    CheckState check();
    bool search();
    bool scoot();
    int checkPath();
    bool turnToFaceCandle();
    bool driveToCandle();

    bool run();
    int minInSample(int i, int ss = 15);

  private:

    int R_TH[360];

    enum State {
      SEARCHING,
      TURNING,
      CHECK_PATH,
      SCOOT,
      CHECKING,
      CHECK_AFTER_SCOOT,
      GO_TO_CANDLE,
      CHECK_FINAL,
      TURN_TO_CANDLE
    };

    const char *stateNames[9] = {
      "SERCHNG      ",
      "TURNNG       ",
      "CHCK_PATH    ",
      "SCOOT        ",
      "CHCKNG       ",
      "CHCK_AFTR_SCT",
      "GO_2_CANDLE  ",
      "CHECK_FINAL  ",
      "TURN_2_CANDLE"
    };

    void changeState(State state);

    State state;

    long lastUpdateTime = 0;

    Point<float> goalPoint;

    float absoluteTurnGoalAngle,
          absoluteCandleAngle;

    int candleCount = 0,
        sweeps = 0;

    const static long UPDATE_PERIOD = 50;
    const static int AVOID_DISTANCE = 400;
};
