#pragma once

#include "FireFinder.hpp"
#include "Lidar.hpp"

class FireFinder : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    FireFinder ff;
};

