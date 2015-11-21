#pragma once

#include "mraa.hpp"

class DriveMotor {

  mraa::Pwm pwm;

  public:
    DriveMotor(int port);
    void set(int speed);

};
