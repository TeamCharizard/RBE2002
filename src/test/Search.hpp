#pragma once

#include "MainSketch.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/Lidar.hpp"
#include <LiquidCrystal.h>

class Search : public MainSketch {
  public:
    Search();
    void setup();
    void loop();

  private:
    Lidar lidar;
    DriveMotor left;
    DriveMotor right;
    int *distances;
    bool turning = false;
    int dFront, dRight, dLeft;
    long last_update, lastMotorLoop;
    bool fullSweep;
    LiquidCrystal lcd;
};
