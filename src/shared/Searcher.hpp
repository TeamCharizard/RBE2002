#pragma once

#include "DriveMotor.hpp"
#include "Lidar.hpp"

class Searcher {
  public:
    DriveDirection getDirection(float direction, int *distances);

  private:
    bool turning = false;
    int dFront, dRight, dLeft;
    float lastDirection;
    bool fullSweep;
};
