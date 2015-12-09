#include <Arduino.h>
#include "PID.hpp"
#include "../main.hpp"

PID::PID(float kP, float kI, float kD, bool feedForward) :
  kP(kP), kI(kI), kD(kD), feedForward(feedForward){}

void PID::set(int setPoint){
  this->setPoint = setPoint;
}

int PID::run(int value){
  int error = setPoint - value;
  iTerm += error;
  //the plus equals is because this is a velocity PID
  if (feedForward){
    output += (kP * error) + kI*iTerm +(kD * (error - lastError ));
  }
  else {
    output = (kP * error) + kI*iTerm +(kD * (error - lastError ));
  }

  lastError = error;
  return output;
}
