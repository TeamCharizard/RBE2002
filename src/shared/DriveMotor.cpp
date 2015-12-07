#include "DriveMotor.hpp"
#include <stdio.h>

void DriveMotor::setup(int port) {
    motor.attach(port, 1000, 2000);
}

// for -100 to 100
void DriveMotor::set(int speed){
    motor.write((((long)speed+100)*180)/200);
/*
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
*/
}
