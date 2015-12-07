#pragma once
#include <Servo.h>

enum DriveDirection {
  FORWARD,
  LEFT,
  RIGHT,
  BACKWARD,
};

class DriveMotor {
private:
    Servo motor;
public:
    void setup(int port);
    void set(int speed);
};
