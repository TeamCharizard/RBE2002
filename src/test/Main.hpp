#pragma once

#include "Robot.hpp"

class Main{

  public:
    void setup();
    void loop();

  private:
    enum RobotState {
      SEARCH_FOR_CANDLE,
      DRIVE_TO_CANDLE,
      FIND_CANDLE_HEIGHT,
      EXTINGUISH_CANDLE,
      RETURN_TO_ORIGIN,
      END
    };
    char* stateNames[6] = {"SEARCH_FOR_CANDLE",
      "DRIVE_TO_CANDLE",
      "CANDLE_HEIGHT",
      "EXTNGISH_CANDLE",
      "RETURN_TO_ORGIN",
      "END"};

    RobotState state = SEARCH_FOR_CANDLE;
    Robot *charizard;
};
