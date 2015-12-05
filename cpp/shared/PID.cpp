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
  iTerm += (error * kI);
  double output = (kP * error) + iTerm +(kD * (error - lastError ));
  lastError = error;
  return output;
}
