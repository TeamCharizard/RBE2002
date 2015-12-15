#pragma once

#include <Arduino.h>
#include "../charizard.hpp"

class StatusManager {
  public:

    /** \brief updates the LCD with the current value of the members */
    static void update();

		/** \brief creates custom LCD character */
		static void setup();
    static void printState(const char* stateString);
    static void printPose();
    static void finalUpdate();
    static int candleX, candleY, candleHeight;
    static int robotX, robotY, robotAngle;
    static const char* state;
    static bool candleFound;

  private:
    static const char *const format[2];
    static byte angleChar[8];
};
