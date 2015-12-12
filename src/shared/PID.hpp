#pragma once

class PID{
  public:
    PID(float kP, float  kI, float kD, bool feedForward);
    void set(float setPoint);
    float run(float value);

    float kP, kI, kD;
    float  lastError,
           iTerm;

    float setPoint;
    float output;

    bool feedForward = false;
};
