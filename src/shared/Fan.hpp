#pragma once

#include <Servo.h>

/** \brief
 * Wrapper around Servo the control 1000KV Outrunner
 */
class Fan{
  public:

    /** \brief Setup for the servo object. Also handles arming of the ESC */
    void setup();

    /** \brief spin the motor at FULL POWER! */
    void spin();

    /** \brief stop the motor. speed controller will ramp it down for us */
    void stop();

  private:

    /** \brief internal motor object */
    Servo motor;

    /** \brief the pause time between ESC arming sequences */
    const static int INIT_PAUSE = 3000;
};
