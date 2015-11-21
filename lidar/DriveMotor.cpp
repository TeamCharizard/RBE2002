#include "DriveMotor.hpp"

DriveMotor::DriveMotor(int port) :
  pwm(port) {
  pwm.period_ms(20);
  pwm.pulsewidth_us(1350);
  pwm.enable(true);
}

void DriveMotor::set(int speed){
  int pulsewidth = speed * 3.5 + 1350;
  pwm.pulsewidth_us(pulsewidth);
}
