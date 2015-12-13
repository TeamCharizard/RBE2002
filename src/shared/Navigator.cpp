#include "Navigator.hpp"
#include "../test/Robot.hpp"

void Navigator::setGoal(Point<float> goal) {
  state = TURNING;
  auto robotPos = Robot::getInstance()->base.pos();
  distance = robotPos.distanceTo(goal);
  angle = atan2(goal.y()-robotPos.y(), goal.x()-robotPos.x());
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
      return true;
    }
    break;
  }
  return false;
}
