#include "Extinguisher.hpp"
#include "../main.hpp"
#include "../test/Robot.hpp"

void Extinguisher::setup(){
  fan.setup();
  state = INIT;
}

bool Extinguisher::run(){
  debugPrint(1,"%s",stateNames[state]);
  switch(state){
    case INIT :
      goalAngle =  Robot::getInstance()->base.dir() + M_PI;
      state = TURNING_TO_BLOW;
      break;
    case TURNING_TO_BLOW:
      if (Robot::getInstance()->turnToFaceAbsolutely(goalAngle)){
        state = BLOWING;
        startStateTime = millis();
      }
      break;
    case TURNING_TO_VERIFY:
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
        goalAngle = M_PI + Robot::getInstance()->base.dir();
        fan.stop();
        state = TURNING_TO_VERIFY;
      }
      break;

    case VERIFYING:
      Robot::getInstance()->stop();
      Robot::getInstance()->base.drive();
      if (millis() - startStateTime > VERIFY_TIME){
        if (!Robot::getInstance()->ff.seesCandle()){
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
