#pragma once

#include "Arduino.h"

class MainSketch {
  public:
    /** \brief pure virtual function for setup. Sublcasses must define */
    void virtual setup() = 0;

    /** \brief pure virtual function for loop. Sublcasses must define */
    void virtual loop() = 0;
};
