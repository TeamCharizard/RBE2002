#include "StatusManager.hpp"

const char *const StatusManager::format[] = {
      "X=%-3d Y=%-3d",
      " =%-3dX=%-3dY=%-2d",
      "H=%-1d.%-2d"};

byte StatusManager::angleChar[] = {
      B00000,
      B00001,
      B00010,
      B00100,
      B01000,
      B10000,
      B11111,
    };

int StatusManager::robotX = 0;
int StatusManager::robotY = 0;
int StatusManager::robotAngle = 0;
int StatusManager::candleX = 0;
int StatusManager::candleY = 0;
int StatusManager::candleHeight = 0;
int StatusManager::candleHeightFrac = 0;
bool StatusManager::candleFound = false;

void StatusManager::setup(){
  Display.createChar(0, angleChar);
}

void StatusManager::printState(const char* stateString){
  Display.setCursor(0,0);
  Display.write(stateString);
}

void StatusManager::printPose(){
  debugPrint(1,format[1],
      robotAngle,robotX,robotY);
  Display.setCursor(1,1);
  Display.write(byte(0)); //write custom angle char
}

void StatusManager::finalUpdate(){
  debugPrint(0,format[0],
      candleX,candleY);
  debugPrint(1,format[2],
      candleHeight,candleHeightFrac);
}
