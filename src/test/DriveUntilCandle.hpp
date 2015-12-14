#pragma once
#include "../MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/PIDBase.hpp"

class DriveUntilCandle : public MainSketch {

    public:
    void setup();
    void loop();
    void avoidInFront(int distance);

  private:
    Lidar lidar;
    PIDBase base;
    int *distances;
    bool foundCandle,
         consideringCandle;
    CandleDetector cd;
    int candleAngle = 0;
    int candleDistance = 0;
    int count = 0;
};
