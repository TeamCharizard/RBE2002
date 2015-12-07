#pragma once

#include "MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/Odom.hpp"

class driveUntilCandle : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    Lidar lidar;
    DriveMotor left;
    DriveMotor right;
    Odom odom;
    int *distances;
    bool stop;
    CandleDetector cd;
    int candleAngle = 0;
    int candleDistance = 0;
    int count = 0;
};
