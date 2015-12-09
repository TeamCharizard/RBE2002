#pragma once

class PID{
  public:
    PID(float kP, float  kI, float kD);
    ~PID();
    void set(int setPoint);
    int run(int value);

    float kP, kI, kD;
    int  lastError,
           iTerm;

    int setPoint;
};
