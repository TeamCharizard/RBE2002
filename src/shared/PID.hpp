#pragma once

class PID{
  public:
    PID(float kP, float  kI, float kD, bool feedForward);
    void set(float setPoint);

    /** this returns an int because motor speeds can't be more precise than an int after scaling */
    int run(float value, bool doWrap = false);

    bool stopped();

    float kP, kI, kD;
    float  lastError,
           iTerm;
    long lastUpdateTime;

    float setPoint;
    int output;

    bool feedForward = false;
};
