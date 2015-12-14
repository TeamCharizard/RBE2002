#pragma once

#include "../shared/Lidar.hpp"
#include "../main.hpp"
#include "../MainSketch.hpp"

class LidarBenchmark : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    Lidar lidar;
    long t0;
};
