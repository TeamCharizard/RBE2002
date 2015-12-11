#include "Extinguisher.hpp"
#include "../test/Robot.hpp"

void Extinguisher::setup(){
  fan.setup();
}

bool Extinguisher::run(){
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
      if (Robot::getInstance()->ff.seesCandle()){
        return true;
      }
      break;
  }
  return false;
}
