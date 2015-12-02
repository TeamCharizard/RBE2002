#include "pwm.hpp"

Pid::Pid(double  kP, double  kI, double  kD){
  this -> kP = kP;
  this -> kI = kI;
  this -> kD = kD;
}

Pid::~Pid(){
}

Pid::setSetpoint(double setPoint){
  this -> setPoint = setPoint;
}

Pid::run(double value){
  double error = setPoint - value;
  iTerm += (error * kI);
  double output = (kP * error) + iTerm +(kD * (error - lastError ));
    lastError = error;
    return output;
}
