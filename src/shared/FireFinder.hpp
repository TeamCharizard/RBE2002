#pragma once

#include "mraa.hpp"

class FireFinder {

  public:

    FireFinder();

    bool scanInFront();

    bool scanAtAngle(int angle);

    bool checkHeightInFront(int distanceToCandle);

    bool checkHeight(int angle, int distanceToCandle);

    mraa::Aio sensor;
    mraa::Pwm head;

  private:

    const static int PIN = 9,
          SENSOR_PIN = 0,
          MAX_HEAD_ANGLE = 65,
          MIN_HEAD_ANGLE = 30,
          SENSOR_HEIGHT = 190;

};
