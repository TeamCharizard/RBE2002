#pragma once

#include <Servo.h>

/** \brief
 * Wrapper around Servo the control 1000KV Outrunner
 */
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

    /** \brief internal motor object */
    Servo motor;

    /** \brief the pause time between ESC arming sequences */
    const static int BUTTON_PIN = 29;

    /** \brief
     * Time for initial pause during initialization of the motor controller
    */
    const static int INIT_PAUSE = 3000;
};
