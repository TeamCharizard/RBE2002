#pragma once

#include <Servo.h>

class Fan{
  public:
    /**
     * Initialize the fan's motor controller
     */
    void setup();

    /**
     * Turn the fan on
     */
    void spin();

    /**
     * Turn the fan off
     */
    void stop();

  private:
    Servo motor;

    //! Time for initial pause during initialization of the motor controller
    const static int INIT_PAUSE = 3000;
};
