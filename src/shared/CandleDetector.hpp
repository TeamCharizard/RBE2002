#pragma once

#include "Point.hpp"

class CandleDetector{

  public:
    CandleDetector();

    /** Looks for candle and returns true if found
     *  assigns values to given pointers for distance and angle
     *  based on input array of distances
      */
    bool detect();

    int distance();
    int angle();
    Point<float> relativePosition();

  private:
    // Add 75 mm to detected candle distance to account for size of base
    const int CANDLE_CENTER_OFFSET = 75;

    int candleDistance = 0,
        candleAngle = 0;

    const static int WIDTH = 130,
          WIDTH_TOLERANCE = 35,
          RADIUS_TOLERANCE = 50,
          MIN_SPIKE = 300,
          MAX_SPIKE = 3000;

    const static float VALID_CANDLE_THRESHOLD;

};
