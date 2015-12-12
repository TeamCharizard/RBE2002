#include "PIDBase.hpp"
#include "Arduino.h"

#include "../main.hpp"

PIDBase::PIDBase() :
  lPID(-0.7,0,0,true),
  rPID(0.7,0,0,true),
  dirPID(13,0.0012,0,false){
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

float PIDBase::dir(){
  return odom.dir;
}

void PIDBase::stop(){
  setSpeeds(0,0);
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

bool PIDBase::turnAbsolutely(float direction){
  dirPID.set(direction);
  odom.updateDifferential();

  int dirOut = dirPID.run(dir());

  setSpeeds(-dirOut,dirOut);

  int dl = odom.leftDisplacement();
  int lOut = lPID.run(dl);
  lMotor.set(lOut);
  int dr = odom.rightDisplacement();
  int rOut = rPID.run(dr);
  rMotor.set(rOut);

  if ( dirOut == 0 && (abs(dir() - direction) < M_PI*4.0/180.0)){
    return true;
  }
  return false;
}

void PIDBase::drive(){
  odom.updateDifferential();

  int dl = odom.leftDisplacement();
  int lOut = lPID.run(dl);
  lMotor.set(lOut);
  int dr = odom.rightDisplacement();
  int rOut = rPID.run(dr);
  rMotor.set(rOut);
}
