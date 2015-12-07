#pragma once

#include "MainSketch.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/DriveMotor.hpp"

class Point : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    void turnToFace(int angle);

    CandleDetector cd;
    Lidar lidar;
    DriveMotor left;
    DriveMotor right;
    int *distances;
};
