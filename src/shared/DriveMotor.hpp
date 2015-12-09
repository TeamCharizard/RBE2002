#pragma once

#include <Servo.h>

enum DriveDirection {
  FORWARD,
  LEFT,
  RIGHT,
  BACKWARD,
};

class DriveMotor {
  public:
    void setup(int port);

    /** set the setpoint for the motor PID
     * @param setpoint the setpoint for the motor setpoint from -100 to 100
     */
    void set(int power);

  private:
    Servo motor;
};
