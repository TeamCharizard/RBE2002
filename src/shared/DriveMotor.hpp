#pragma once
#include <Servo.h>

class DriveMotor {
private:
    Servo motor;
public:
    void setup(int port);
    void set(int speed);
};
