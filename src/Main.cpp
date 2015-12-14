#include "Main.hpp"
#include "main.hpp"
#include "Robot.hpp"

void Main::setup(){
  charizard = Robot::getInstance();
  charizard->setup();
  state = SEARCH_FOR_CANDLE;

  debugPrint(0,stateNames[state]);
}

void Main::loop(){
  switch(state){
    case SEARCH_FOR_CANDLE:
      if (charizard->search()){
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
        state = RETURN_TO_ORIGIN;
        Robot::getInstance()->popWaypoint();
        debugPrint(0,stateNames[state]);
      }
      break;
    case RETURN_TO_ORIGIN:
      if (charizard->returnToOrigin()){
        state = END;
        debugPrint(0,stateNames[state]);
      }
      break;
    case END:
      charizard->end();
      break;
  }
}
