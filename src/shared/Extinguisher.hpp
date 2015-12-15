#pragma once
/** \brief
 *  Houses the state machine for extinguishing the candle.
 *  Fan is included
 * */
#include "Fan.hpp"

class Extinguisher {
  private:
    /** \brief The different states for the extinguisher routine */
    enum State{
      INIT,
      TURNING_TO_BLOW,
      TURNING_TO_VERIFY,
      BLOWING,
      VERIFYING
    };


  public:
    /** \brief Setup fan and state machine. Called by main setup */
    void setup();

    /** \brief Change and print the state */
    void changeState(State state);

    /** \brief state machine method. States listed in stateNames */
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
