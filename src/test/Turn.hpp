#pragma once

#include "MainSketch.hpp"

class Turn : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    float direction;
    long lastUpdateTime;
};
