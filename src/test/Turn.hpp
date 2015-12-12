#pragma once

#include "../shared/PIDBase.hpp"
#include "MainSketch.hpp"

class Turn : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    PIDBase base;
    float direction;
    bool turning;
};
