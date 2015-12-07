#pragma once

#include "DriveMotor.hpp"
#include "Lidar.hpp"

class Searcher {
  public:
    DriveDirection getDirection();

  private:
    Lidar lidar;
    int *distances;
    bool turning = false;
    int dFront, dRight, dLeft;
    long last_update, now;
    bool fullSweep;
};
