#pragma once

#include "MainSketch.hpp"
#include "../shared/FireFinder.hpp"
#include "../shared/Lidar.hpp"

class FireFinder : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    FireFinder ff;
};

