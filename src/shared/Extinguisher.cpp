#include "Extinguisher.hpp"
#include "../main.hpp"
#include "../test/Robot.hpp"

void Extinguisher::setup(){
  fan.setup();
  state = BLOWING;
  startSpinTime = millis();
}

bool Extinguisher::run(){
  //debugPrint(1,"%s",stateNames[state]);
  switch(state){
    case TURNING_TO_BLOW:
      {
        float newAngle = 1.5707 + Robot::getInstance()->base.dir();
        bool doneTurning = Robot::getInstance()->turnToFace(newAngle);
        if (doneTurning){
          state = TURNING_TO_BLOW;
          startSpinTime = millis();
        }
      }
      break;

    case TURNING_TO_VERIFY:
      {
        //calculate 180 off current angle and turn to that angle
        float newAngle = 1.5707 + Robot::getInstance()->base.dir();
        bool doneTurning = Robot::getInstance()->turnToFace(newAngle);
        if (doneTurning){
          state = VERIFYING;
        }
      }
      break;

    case BLOWING:
      fan.spin();
      if (millis() - startSpinTime > SPIN_TIME){
        fan.stop();
        state = VERIFYING;
      }
      break;

    case VERIFYING:
      bool found = Robot::getInstance()->ff.seesCandle();
      if (found){
        return true;
      }
      break;
  }
  return false;
}
