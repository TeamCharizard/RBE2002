#pragma once

#include "PID.hpp"
#include <Servo.h>

enum DriveDirection {
  FORWARD,
  LEFT,
  RIGHT,
  BACKWARD,
};

class DriveMotor {
  public:
    DriveMotor(float kP, float kI, float kD);
    PID pid;
    void setup(int port);

    /** set the setpoint for the motor PID
     * @param setpoint the setpoint for the motor setpoint from -100 to 100
     */
    void set(int setpoint);
  private:
    Servo motor;
    int setpoint;
};
