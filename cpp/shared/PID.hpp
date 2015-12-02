#pragma once

class PID{
 private
  double kP;
  double kI;
  double kD;
  double setpoint;
  double lastError;
  double iTerm;

public
  void  PID::PID(double  kP, double kI, double kD);
  void  PID::~PID();
  void  PID::setSetpoint(double setPoint);
  double  PID::run(double value);
