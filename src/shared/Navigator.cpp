#include "Navigator.hpp"
#include "../test/Robot.hpp"

Navigator::Navigator() : distPid(-3.8, 0, 15, false) {}

void Navigator::setGoal(Point<float> goal) {
  state = TURNING;
  auto robotPos = Robot::getInstance()->base.pos();
  distance = robotPos.distanceTo(goal);
  float dX = goal.x()-robotPos.x();
  float dY = goal.y()-robotPos.y();
  angle = atan2(dY, dX);
  distPid.set(0.0);
}

bool Navigator::run() {
  switch(state) {
  case TURNING:
    if(Robot::getInstance()->turnToFaceAbsolutely(angle)) {
      state = DRIVING;
    }
    break;
  case DRIVING:

    float traveled = Robot::getInstance()->base.drive();
    distance -= traveled;
    float power = distPid.run(distance);
    power = min(100, max(-100, power));
    Robot::getInstance()->base.setSpeeds(power, power);

    if(Robot::getInstance()->base.stopped() && abs(distance) < 1.0) {
      return true;
    }

    break;
  }
  return false;
}
