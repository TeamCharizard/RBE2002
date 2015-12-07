#pragma once

class PID{
  public:
    PID(double kP, double kI, double kD);
    ~PID();
    void setSetpoint(double setPoint);
    double run(double value);

  private:
    double kP, kI, kD;
    double setPoint,
           lastError,
           iTerm;
};
