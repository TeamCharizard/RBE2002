#include <Arduino.h>
#include "PID.hpp"
#include "../main.hpp"

PID::PID(float kP, float kI, float kD){
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
}

PID::~PID(){
}

void PID::set(int setPoint){
  Serial.println(setPoint);
  this->setPoint = setPoint;
}

int PID::run(int value){
  int error = setPoint - value;
  iTerm += error;
  //the plus equals is because this is a velocity PID
  output += (kP * error) + kI*iTerm +(kD * (error - lastError ));

  lastError = error;
  return output;
}
