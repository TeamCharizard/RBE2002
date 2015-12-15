#pragma once

#include <Arduino.h>
#include "../charizard.hpp"

/** \brief Wrapper class around the Display in charizard.
 * Allows for clean printing and custom characters
 */
class StatusManager {
  public:

    /** \brief updates the LCD with the current value of the members */
    static void update();

		/** \brief creates custom LCD character */
		static void setup();
    static void printState(const char* stateString);
    static void printPose();
    static void finalUpdate();
    static int candleX, candleY, candleHeight, candleHeightFrac;
    static int robotX, robotY, robotAngle;
    static const char* state;
    static bool candleFound;

  private:
    static const char *const format[3];
    static byte angleChar[8];
};
