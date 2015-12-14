#include "DriveMotor.hpp"
#include <stdio.h>
#include "Arduino.h"

void DriveMotor::setup(int port) {
  motor.attach(port, 1000, 2000);
}

void DriveMotor::stop(){
  motor.write(90);
}

// for -100 to 100
void DriveMotor::set(int power){
  long scaledUp = (power + 100l) * 180l;
  power = scaledUp / 200;
  if (power > 180) power = 180;
  if (power < 0) power = 0;
  motor.write(power);
}
