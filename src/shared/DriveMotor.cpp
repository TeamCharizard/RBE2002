#include "DriveMotor.hpp"
#include <stdio.h>

DriveMotor::DriveMotor(float kP, float kI, float kD) :
    PID(kP,kI,kD) {

}

void DriveMotor::setup(int port) {
  motor.attach(port, 1000, 2000);
}

// for -100 to 100
void DriveMotor::set(int setpoint){
  this->setPoint = setPoint;
  //motor.write((((long)speed+100)*180)/200);
}

int DriveMotor::run(int value){
  int error = setPoint - value;
  iTerm += error;
  int output = (kP * error) + kI*iTerm +(kD * (error - lastError ));
  lastError = error;
  return output;
}

