#pragma once

#include <LiquidCrystal.h>
#include <Servo.h>

/** using global extern makes this avaiable to all other files */
extern LiquidCrystal Display;

/** debug print to the LCD */
void debugPrint(int line, const char *format, ... );
