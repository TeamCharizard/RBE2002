#include "PIDBase.hpp"
#include "Arduino.h"

#include "../charizard.hpp"

PIDBase::PIDBase() :
  lPID(-1.0,0,0,true),
  rPID(1.0,0,0,true),
  dirPID(-50,0.0,9.5,false){
  }

void PIDBase::setup(){
  rMotor.setup(8);
  lMotor.setup(9);
  setSpeeds(0,0);
  odom.setup();
}

float PIDBase::x(){
  return odom.getPos().x();
}

float PIDBase::y(){
  return odom.getPos().y();
}

bool PIDBase::stopped() {
  return lPID.stopped() && rPID.stopped();
}

Point<float> PIDBase::pos() {
  return odom.getPos();
}

float PIDBase::dir(){
  return odom.dir;
}

void PIDBase::stop(){
  setSpeeds(0,0);
}

void PIDBase::hardStop(){
  lMotor.stop();
  rMotor.stop();
}

void PIDBase::setSpeeds(int leftSpeed, int rightSpeed){
  int l = scale(leftSpeed);
  int r = scale(rightSpeed);
  lPID.set(l);
  rPID.set(r);
}

int PIDBase::scale(int speed){
  return ((speed + 100) * 2 * TOP_SPEED) / 200 - TOP_SPEED;
}

float PIDBase::normalize(float angle) {
    float tmp = fmod(angle, 2 * M_PI);
    return tmp < 0 ? tmp + 2 * M_PI : tmp;
}

bool PIDBase::turnAbsolutely(float direction){
  float setpoint = normalize(direction);
  float current = normalize(dir());

  dirPID.set(setpoint);
  odom.updateDifferential();

  int dirOut = dirPID.run(current, true);

  setSpeeds(-dirOut,dirOut);

  int dl = odom.leftDisplacement();
  int lOut = lPID.run(dl);
  lMotor.set(lOut);
  int dr = odom.rightDisplacement();
  int rOut = rPID.run(dr);
  rMotor.set(rOut);

  float angleError = abs(current - setpoint);

  /*
   *Serial.print("error=");
   *Serial.print(angleError);
   *Serial.print("dirOut=");
   *Serial.println(dirOut);
   */

  //debugPrint(1,"err=%-3d            ",  (int)(angleError*180/M_PI));
  if ( rPID.stopped() && lPID.stopped() &&
      (angleError < M_PI*4.0/180.0)){
    return true;
  }
  return false;
}

float PIDBase::drive(){
  float dist = odom.updateDifferential();

  int dl = odom.leftDisplacement();
  int lOut = lPID.run(dl);
  lMotor.set(lOut);
  int dr = odom.rightDisplacement();
  int rOut = rPID.run(dr);
  rMotor.set(rOut);

  return dist;
}
