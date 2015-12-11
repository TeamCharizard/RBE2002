#pragma once

#include <Servo.h>

class Fan{
  public:
    void setup();
    void spin();
    void stop();

  private:
    Servo motor;
    const static int INIT_PAUSE = 2000;
};
