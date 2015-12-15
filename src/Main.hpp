#pragma once

#include "Robot.hpp"

class Main{
  private:
    /** \brief The main states of the robot */
    enum State {
      SEARCH_FOR_CANDLE,
      FIND_CANDLE_HEIGHT,
      EXTINGUISH_CANDLE,
      RETURN_TO_ORIGIN,
      END
    };

  public:
    /** \brief setup method calls setup for robot */
    void setup();

    /** \brief main state machine controls overall program flow */
    void loop();

    /** \brief change state and print state */
    void changeState(State state);

  private:

    /** \brief English state names allows us to easily print what state the
     * robot is in */
    char* stateNames[5] = {
      "SEARCH_4_CANDLE",
      "CANDLE_HEIGHT  ",
      "EXNTIGISH_CANDLE",
      "RETRN_TO_ORGIN ",
      "END            "};

    /** \brief variable for the current state of the robot. */
    State state = SEARCH_FOR_CANDLE;

    /** \brief convenient pointer to the singleton robot instance */
    Robot *charizard;
};
