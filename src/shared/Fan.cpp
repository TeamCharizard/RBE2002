#include "Fan.hpp"

void Fan::setup(){
  motor.attach(11);
  motor.write(180);
  delay(INIT_PAUSE);
  motor.write(0);
  delay(INIT_PAUSE);
}

void Fan::spin(){
  motor.write(180);
}

void Fan::stop(){
  motor.write(0);
}
