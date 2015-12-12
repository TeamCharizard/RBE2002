#include <Arduino.h>
#include "PID.hpp"
#include "../main.hpp"

PID::PID(float kP, float kI, float kD, bool feedForward) :
  kP(kP), kI(kI), kD(kD), feedForward(feedForward), output(1) {}

void PID::set(float setPoint){
  this->setPoint = setPoint;
}

float PID::run(float value){
  float error = setPoint - value;
  iTerm += error;
  //the plus equals is because this is a velocity PID
  if (feedForward){
    output += (kP * error) + kI*iTerm +(kD * (error - lastError ));
  }
  else {
    output = (kP * error) + kI*iTerm +(kD * (error - lastError ));
  }

  //debugPrint(1,"%d %d",error,value);
  lastError = error;
  return output;
}
