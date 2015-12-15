#pragma once

#include <Servo.h>

class Fan{
  public:
    /** \brief
     * Initialize the fan's motor controller. 
     * Waits for button to be released before initializing
     */
    void setup();

    /** \brief
     * Turn the fan on
     */
    void spin();

    /** \brief
     * Turn the fan off
     */
    void stop();

  private:
    Servo motor;
    const static int BUTTON_PIN = 29;
    
    /** \brief
     * Time for initial pause during initialization of the motor controller
    */
    const static int INIT_PAUSE = 3000;
};
