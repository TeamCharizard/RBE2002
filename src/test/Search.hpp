#pragma once

#include "MainSketch.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/Lidar.hpp"

class Search : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    Lidar lidar;
    DriveMotor left;
    DriveMotor right;
    int *distances;
    bool turning = false;
    int dFront, dRight, dLeft;
    long last_update, now;
    bool fullSweep;
};
