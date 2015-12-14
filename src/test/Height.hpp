#pragma once

#include "../MainSketch.hpp"
#include "../shared/FireFinder.hpp"
#include "../shared/Lidar.hpp"

class Height : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    FireFinder ff;
};

