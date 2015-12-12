#pragma once

#include "Fan.hpp"

enum State{
  INIT,
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

    long startStateTime = 0l;
    float startPosition = 0;
    float goalAngle = 0.0f;
    const static int BLOW_TIME = 6000,
          VERIFY_TIME = 2000;

    const char *stateNames[5] = {
      "INIT          ",
      "TURNING_BLOW  ",
      "TURNING_VERIFY",
      "BLOWING       ",
      "VERIFYING     "};

};
