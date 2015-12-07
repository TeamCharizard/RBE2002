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

bool Robot::search(){
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
    
    
