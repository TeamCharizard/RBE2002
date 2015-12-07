#pragma once
#include "MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/Odom.hpp"

class DriveUntilCandle : public MainSketch {

    public:
    void setup();
    void loop();
    void avoidInFront(int distance);

  private:
    Lidar lidar;
    DriveMotor left;
    DriveMotor right;
    typedef Encoder<2,3> LeftEnc;
    typedef Encoder<18,19> RightEnc;
    Odom<LeftEnc, RightEnc> odom;
    int *distances;
    bool stop;
    CandleDetector cd;
    int candleAngle = 0;
    int candleDistance = 0;
    int count = 0;
};
