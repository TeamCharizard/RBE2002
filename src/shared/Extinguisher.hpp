#pragma once
/** \brief
 *  houses the state machine for extinguishing the candle
 *  Fan is included
 * */
#include "Fan.hpp"

class Extinguisher {
  private:
    enum State{
      INIT,
      TURNING_TO_BLOW,
      TURNING_TO_VERIFY,
      BLOWING,
      VERIFYING
    };


  public:
    /** \brief setup fan and state machine. Called my main setup */
    void setup();
    void changeState(State state);

    /** \brief state machine method. States liste in *stateNames */
    bool run();

  private:
    /** \brief Extinguishing fan */
    Fan fan;

    /** \brief State Machine control variable */
    State state;

    /** \brief Timer variable for time based states */
    long startStateTime = 0l;

    /** \brief Goal Angle to face after turns */
    float goalAngle = 0.0f;

    /** \brief Length of timers */
    const static int BLOW_TIME = 6000,
          VERIFY_TIME = 2000;

    /** \brief Names of States */
    const char *stateNames[5] = {
      "INIT          ",
      "TURNING_BLOW  ",
      "TURNING_VERIFY",
      "BLOWING       ",
      "VERIFYING     "};

};
