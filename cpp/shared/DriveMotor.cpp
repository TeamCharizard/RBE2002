#include "DriveMotor.hpp"
#include "stdio.h"

DriveMotor::DriveMotor(int port) :
  pwm(port) {
  pwm.period_ms(20);
  pwm.pulsewidth_us(1350);
  pwm.enable(true);
}

DriveMotor::~DriveMotor(){
  pwm.pulsewidth_us(1350);
  pwm.enable(false);
}

// for -100 to 100
void DriveMotor::set(int speed){
  if (speed > 5){
    speed = 20 + speed;
  }
  int pulsewidth = speed * 3.5 + 1350;

  if (pulsewidth > 2000){
    pulsewidth = 2000;
  }

  if (pulsewidth < 1000){
    pulsewidth = 1000;
  }
  pwm.pulsewidth_us(pulsewidth);
}