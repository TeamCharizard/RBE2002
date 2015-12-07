#pragma once

#include "../shared/DriveMotor.hpp"
#include "../shared/Lidar.hpp"

class Search : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    Lidar lidar;
    DriveMotor left(6);
    DriveMotor right(5);
    int *distances;
    bool turning = false;
    int dFront, dRight, dLeft;
    long last_update, now;
    bool fullSweep;
};
