#pragma once

#include <LiquidCrystal.h>
#include <Servo.h>

extern LiquidCrystal Display;

/** debug print to the LCD */
void debugPrint(int line, const char *format, ... );
