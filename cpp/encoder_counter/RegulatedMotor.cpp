#include "Encoder.hpp"
#include "RegulatedMotor.hpp"
#include "stdio.h"
#include "DriveMotor.hpp"

RegulatedMotor::RegulatedMotor(int motorPort, int port1, int port2){
  DriveMotor::DriveMotor(motorPort);
  encoder(port1,port2);
}

RegulatedMotor::~RegulatedMotor(){
  DriveMotor::~DriveMotor();
}

void RegulatedMotor::set(int speed){
  #TODO;
}
