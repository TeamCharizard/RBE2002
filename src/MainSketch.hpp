#pragma once

#include "Arduino.h"

/** \brief This class is used by charizard.
 * Main and other test sketches should extend this class
 * and implement setup and loop
 */
class MainSketch {
  public:
    /** \brief pure virtual function for setup. Sublcasses must define */
    void virtual setup() = 0;

    /** \brief pure virtual function for loop. Sublcasses must define */
    void virtual loop() = 0;
};
