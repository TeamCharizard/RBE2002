#include "main.hpp"

//#include "systems/Robot.hpp"
#include <Arduino.h>
#include <CommanDuino.h>
//#include "commands/IChooseYou.hpp"

LiquidCrystal Display(40,41,42,43,44,45);

Command *cmd;

void debugPrint(int line, const char *format, ...){
  va_list args;
  va_start(args, format);

  char msg[16];
  vsnprintf(msg, sizeof(msg), format, args);
  Serial.println(msg);
  Display.setCursor(0,line);
  Display.print(msg);

  va_end(args);
}

void setup(){
  Display.begin(16,2);
  Serial.begin(9600);
  //robot.setup();
}

void loop(){
  /*
   *if (Robot::MODE == LIDAR){
   *  bool fullSweep = lidar.read():
   *  if (fullSweep){
   *    Scheduler::getInstance()->run();
   *  }
   *}
   *else if (Robot::MODE == ODOM){
   *  long now = millis();
   *  if (now - lastUpdateTime > ODOM_FREQ){
   *    Scheduler::getInstance()->run();
   *  }
   *}
   */
}
