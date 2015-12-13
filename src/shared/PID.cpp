#include <Arduino.h>
#include "PID.hpp"
#include "../main.hpp"

PID::PID(float kP, float kI, float kD, bool feedForward) :
  kP(kP),  kI(kI),  kD(kD),
  feedForward(feedForward), output(1),iTerm(0) {}

  void PID::set(float setPoint){
    this->setPoint = setPoint;
  }

bool PID::stopped(){
  if (feedForward){
    return abs(lastError) < 2 && abs(setPoint) < 2;
  }
  return false;
}

int PID::run(float value, bool doWrap){
  float error = setPoint - value;

  if (doWrap && error > M_PI) {
    error -= 2 * M_PI;
  }
  if (doWrap && error < -M_PI) {
    error += 2 * M_PI;
  }

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
