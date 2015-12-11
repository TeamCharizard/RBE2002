#include "Main.hpp"
#include "../main.hpp"
#include "Robot.hpp"

void Main::setup(){
  charizard = Robot::getInstance();
  charizard->setup();
  state = EXTINGUISH_CANDLE;
  debugPrint(0,stateNames[state]);
}

void Main::loop(){
  switch(state){
    case SEARCH_FOR_CANDLE:
      if (charizard->search()){
        state = DRIVE_TO_CANDLE;
        debugPrint(0,stateNames[state]);
      }
      break;
    case DRIVE_TO_CANDLE:
      if (charizard->driveToCandle()){
        state = FIND_CANDLE_HEIGHT;
        debugPrint(0,stateNames[state]);
      }
      break;
    case FIND_CANDLE_HEIGHT:
      if (charizard->findCandleHeight()){
        state = EXTINGUISH_CANDLE;
        debugPrint(0,stateNames[state]);
      }
      break;
    case EXTINGUISH_CANDLE:
      if (charizard->extinguishCandle()){
        //state = RETURN_TO_ORIGIN;
        debugPrint(0,stateNames[state]);
      }
      break;
    case RETURN_TO_ORIGIN:
      if (charizard->returnToOrigin()){
        state = END;
        debugPrint(0,stateNames[state]);
      }
      break;
  }
}


