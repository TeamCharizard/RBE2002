#pragma once

#include "Arduino.h"

class MainSketch {
  public:
    void virtual setup() = 0;
    void virtual loop() = 0;
};
