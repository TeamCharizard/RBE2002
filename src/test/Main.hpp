#pragma once

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
    DriveMotor left(6);
    DriveMotor right(5);
    Odom odom(12, 13, 8, 11);
    int *distances;
    bool stop;
    CandleDetector cd;
    int candleAngle = 0;
    int candleDistance = 0;
    int count = 0;
};
