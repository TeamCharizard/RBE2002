#include "charizard.hpp"

#include "Main.hpp"
#include "test/TestGyro.hpp"

LiquidCrystal Display(40,41,42,43,44,45);

Main sketch;

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
  sketch.setup();
}

void loop(){
  sketch.loop();
}
