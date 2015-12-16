#include "Main.hpp"
#include "charizard.hpp"
#include "shared/StatusManager.hpp"
#include "Robot.hpp"

void Main::setup(){
  charizard = Robot::getInstance();
  charizard->setup();
  changeState(RETURN_TO_ORIGIN);
}

void Main::changeState(State state){
  this->state = state;
  StatusManager::printState(stateNames[state]);
}

void Main::loop(){
  switch(state){
    case SEARCH_FOR_CANDLE:
      if (charizard->search()){
        changeState(FIND_CANDLE_HEIGHT);
      }
      break;
    case FIND_CANDLE_HEIGHT:
      if (charizard->findCandleHeight()){
        changeState(EXTINGUISH_CANDLE);
      }
      break;
    case EXTINGUISH_CANDLE:
      if (charizard->extinguishCandle()){
        changeState(RETURN_TO_ORIGIN);
        Robot::getInstance()->popWaypoint();
      }
      break;
    case RETURN_TO_ORIGIN:
      if (charizard->returnToOrigin()){
        state = END;
      }
      break;
    case END:
      charizard->end();
      break;
  }
}
