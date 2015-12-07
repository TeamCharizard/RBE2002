#pragma once

class DriveMotor {

  mraa::Pwm pwm;

  public:
    DriveMotor(int port);
    ~DriveMotor();
    void set(int speed);

};
