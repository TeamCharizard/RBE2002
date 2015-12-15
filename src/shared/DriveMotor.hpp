#pragma once

#include <Servo.h>

/** \brief The basic directions to drive */
enum DriveDirection{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

class DriveMotor {
  public:
    /** \brief setup motor */
    void setup(int port);

    /** \brief Set the setpoint for the motor PID
     * \param setpoint the setpoint for the motor setpoint from -100 to 100
     */
    void set(int power);

    /** \brief stops super hard */
    void stop();

  private:

    /** \brief internal motor object */
    Servo motor;
};
