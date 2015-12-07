#pragma once

#include "MainSketch.hpp"
#include "../shared/Odom.hpp"
#include "../shared/Point.hpp"

class PrintOdom : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    Odom odom;
};
