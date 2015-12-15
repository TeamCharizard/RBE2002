#include <Arduino.h>
#include "PID.hpp"
#include "../charizard.hpp"

PID::PID(float kP, float kI, float kD, bool feedForward) :
  kP(kP),  kI(kI),  kD(kD), lastUpdateTime(-1),
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
  long now = millis();
  if(lastUpdateTime < 0) { lastUpdateTime = now; return 0; }
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
    //Serial.print("err uns=");
    //Serial.println(error);
    //error *= (now-lastUpdateTime);
    //Serial.print("err=");
    //Serial.println(error);
    //Serial.print("t=");
    //Serial.println(now-lastUpdateTime);
    output += (kP * error) + kI*iTerm*(now-lastUpdateTime) +(kD * (error - lastError ) / (float)(now-lastUpdateTime));
    //Serial.print("out=");
    //Serial.println(output);
    if(output > 100) output = 100;
    if(output < -100) output = -100;
  }
  else {
    output = (kP * error) + kI*iTerm*(now-lastUpdateTime) +(kD * (error - lastError ) / (float)(now-lastUpdateTime));
  }

  lastError = error;
  lastUpdateTime = now;
  return output;
}
