#include "PIDBase.hpp"

#include "../main.hpp"

PIDBase::PIDBase() :
  lPID(0.7,0,0,true),
  rPID(0.7,0,0,true){
  }

void PIDBase::setup(){
  rMotor.setup(8);
  lMotor.setup(9);
  setSpeeds(0,0);
  odom.setup();
  lastUpdate = millis();
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
  //Serial.print(scale(leftSpeed));
  //Serial.print(" ");
  //Serial.println(scale(rightSpeed));

  lPID.set(scale(leftSpeed));
  rPID.set(scale(rightSpeed));
}

int PIDBase::scale(int speed){
  return ((speed + 10) * 2 * TOP_SPEED) / 20 - TOP_SPEED;
}

void PIDBase::run(){
  odom.updateDifferential();

  int dl = odom.leftDisplacement();
  int lOut = lPID.run(dl);
  lMotor.set(lOut);
  int dr = odom.rightDisplacement();
  int rOut = rPID.run(dr);
  rMotor.set(-rOut);
//    char msg[16];
//    snprintf(msg, 16, "lS=%-3d lR=%-3d",scale(dl),scale(dr));
//    Display.setCursor(0,1);
//    Display.print(msg);

}
