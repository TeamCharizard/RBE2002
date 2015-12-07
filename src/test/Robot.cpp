#include "Robot.hpp"

Robot::Robot(){
  left.setup(5);
  right.setup(6);
  lidar.setup();
  odom.setup();
}

Robot *Robot::getInstance(){
  if(instance == NULL){
    instance = new Robot();
  }
  return instance;

}

void Robot::drive(DriveDirection dir){
  if (dir == DriveDirection::FORWARD){
    right.set(50);
    left.set(-50);
  }
  else if (dir == DriveDirection::LEFT){
    right.set(50);
    left.set(50);
  }
  else if (dir == DriveDirection::RIGHT){
    right.set(-50);
    left.set(-50);
  }
  else if (dir == DriveDirection::BACKWARD){
    right.set(-50);
    left.set(50);
  }
}

bool Robot::search(){
  DriveDirection dir = searcher.getDirection();
  drive(dir);
  return false;
}

bool Robot::driveToCandle(){
  return false;
}

bool Robot::findCandleHeight(){
  return false;
}

bool Robot::extinguishCandle(){
  return false;
}

bool Robot::returnToOrigin(){
  return false;
}


