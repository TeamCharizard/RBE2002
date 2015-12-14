#include "Navigator.hpp"
#include "../test/Robot.hpp"

void Navigator::setGoal(Point<float> goal) {
  state = TURNING;
  auto robotPos = Robot::getInstance()->base.pos();
  distance = robotPos.distanceTo(goal);
  float dX = goal.x()-robotPos.x();
  float dY = goal.y()-robotPos.y();
  Serial.print("dist=");
  Serial.println(distance);
  angle = atan2(dY, dX);
}

bool Navigator::run() {
  switch(state) {
  case TURNING:
    if(Robot::getInstance()->turnToFaceAbsolutely(angle)) {
      state = DRIVING;
    }
    break;
  case DRIVING:
    Robot::getInstance()->setDrive(FORWARD);
    distance -= Robot::getInstance()->base.drive();
    if(distance <= 0) {
      Robot::getInstance()->hardStop();
      delay(100);
      return true;
    }
    break;
  }
  return false;
}
