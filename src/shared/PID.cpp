#include "PID.hpp"

PID::PID(float kP, float kI, float kD){
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
}

PID::~PID(){
}

void PID::set(int setPoint){
  this->setPoint = setPoint;
}

int PID::run(int value){
  int error = setPoint - value;
  iTerm += error;
  int output = (kP * error) + kI*iTerm +(kD * (error - lastError ));
  lastError = error;
  return output;
}
