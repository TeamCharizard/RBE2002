#pragma once

#include "Robot.hpp"

class Main{
  public:
    void setup();
    void loop();

  private:
    enum RobotState {
      SEARCH_FOR_CANDLE,
      FIND_CANDLE_HEIGHT,
      EXTINGUISH_CANDLE,
      RETURN_TO_ORIGIN,
      END
    };
    char* stateNames[5] = {
      "SEARCH_4_CANDLE",
      "CANDLE_HEIGHT  ",
      "EXNTIGISH_CANDLE",
      "RETRN_TO_ORGIN ",
      "END            "};

    RobotState state = SEARCH_FOR_CANDLE;
    Robot *charizard;
};
