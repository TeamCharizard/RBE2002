#include "Extinguisher.hpp"
#include "../charizard.hpp"
#include "../Robot.hpp"

void Extinguisher::setup(){
  fan.setup();
  state = INIT;
}

void Extinguisher::changeState(State state){
  state =  state;
  StatusManager::printState(stateNames[state]);
}

bool Extinguisher::run(){
  switch(state){
    case INIT :
      goalAngle =  Robot::getInstance()->base.dir() - M_PI;
      state = TURNING_TO_BLOW;
      break;
    case TURNING_TO_BLOW:
      if (Robot::getInstance()->turnToFaceAbsolutely(goalAngle)){
        state = BLOWING;
        startStateTime = millis();
      }
      break;
    case TURNING_TO_VERIFY:
      Robot::getInstance()->ff.levelHead();
      if (Robot::getInstance()->turnToFaceAbsolutely(goalAngle)){
        state = VERIFYING;
        startStateTime = millis();
      }
      break;
    case BLOWING:
      Robot::getInstance()->stop();
      Robot::getInstance()->base.drive();
      fan.spin();
      if (millis() - startStateTime > BLOW_TIME){
        goalAngle = Robot::getInstance()->base.dir() - M_PI;
        fan.stop();
        state = TURNING_TO_VERIFY;
      }
      break;

    case VERIFYING:
      Robot::getInstance()->stop();
      Robot::getInstance()->base.drive();
      if (millis() - startStateTime > VERIFY_TIME){
        if (!Robot::getInstance()->ff.seesCandle()){
          Robot::getInstance()->ledsOff();
          return true;
        }
        else {
          state = TURNING_TO_BLOW;
          goalAngle =  Robot::getInstance()->base.dir() + M_PI;
        }
        break;
      }
  }
  return false;
}
