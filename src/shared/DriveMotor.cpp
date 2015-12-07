#include "DriveMotor.hpp"
#include <stdio.h>

DriveMotor::DriveMotor(float kP, float kI, float kD) :
  pid(kP,kI,kD) {
    //pid();
}

void DriveMotor::setup(int port) {
  motor.attach(port, 1000, 2000);
}

// for -100 to 100
void DriveMotor::set(int setpoint){
  this->setpoint = setpoint;
  //motor.write((((long)speed+100)*180)/200);
}

