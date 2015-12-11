#pragma once

#include "Fan.hpp"

enum State{
  TURNING_TO_BLOW,
  TURNING_TO_VERIFY,
  BLOWING,
  VERIFYING
};

class Extinguisher {
  public:
    void setup();
    bool run();

  private:
    Fan fan;
    State state;

    long startSpinTime = 0l;
    const static int SPIN_TIME = 5000;

};
