#include "Main.hpp"
#include "Robot.hpp"

void Main::setup(){
    charizard = Robot::getInstance();
    charizard->setup();
}

void Main::loop(){
    switch(state){
        case SEARCH_FOR_CANDLE:
            if (charizard->search()){
                state = DRIVE_TO_CANDLE;
            }
            break;
        case DRIVE_TO_CANDLE:
            if (charizard->driveToCandle()){
                state = FIND_CANDLE_HEIGHT;
            }
            break;
        case FIND_CANDLE_HEIGHT:
            if (charizard->findCandleHeight()){
                state = EXTINGUISH_CANDLE;
            }
            break;
        case EXTINGUISH_CANDLE:
            if (charizard->extinguishCandle()){
                state = RETURN_TO_ORIGIN;
            }
            break;
        case RETURN_TO_ORIGIN:
            if (charizard->returnToOrigin()){
                state = END;
            }
           break;
    }
}


