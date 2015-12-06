#include "PID.hpp"

PID::PID(double kP, double kI, double kD){
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
}

PID::~PID(){
}

void PID::setSetpoint(double setPoint){
  this->setPoint = setPoint;
}

double PID::run(double value){
  double error = setPoint - value;
  iTerm += error;
  double output = (kP * error) + kI*iTerm +(kD * (error - lastError ));
  lastError = error;
  return output;
}
