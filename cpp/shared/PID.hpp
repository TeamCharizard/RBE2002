#pragma once

Class Pid{
 private
  double kP;
  double kI;
  double kD;
  double setpoint;
  double lastError;
  double iTerm;

public
  void  Pid::Pid(double  kP, double kI, double kD);
  void  Pid::~Pid();
  void  Pid::setSetpoint(double setPoint);
  double  Pid::run(double value);
