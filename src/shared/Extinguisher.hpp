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
    float startPosition = 0;
    const static int SPIN_TIME = 5000;

    const char *stateNames[4] = {"TURNING_TO_BLOW",
      "TURNING_TO_VERIFY",
      "BLOWING",
      "VERIFYING"};

};
