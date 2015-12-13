#include "Robot.hpp"

long Robot::lastUpdateTime = 0ul;
Robot::Mode Robot::mode = NOTHING;
Lidar Robot::lidar;

void Robot::setup(){
  /*
   * lidar.setup()
   * base.setup()
   * ff.setup()
   * extinguisher.setup()
   * gyro.setup()
   */
}

Robot::Mode Robot::getMode(){
  return mode;
}

void Robot::setMode(Mode mode){
  Robot::mode = mode;
}
