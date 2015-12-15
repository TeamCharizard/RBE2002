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

    /**
     * \brief Get the distance to the last detected candle
     * \return the distance to the last detected candle in millimeters
     */
    int distance();
    /**
     * \brief Get the angle to the last detected candle
     * \return the distance to the last detected candle in degrees
     */
    int angle();

    /**
     * \brief Get the relative position of the last detected candle
     * \return The x,y coordinates of the last detected candle in inches
     */
    Point<float> relativePosition();

  private:
    // Add offset detected candle distance to account for size of base
    const int CANDLE_CENTER_OFFSET = 40;

    int candleDistance = 0,
        candleAngle = 0;

    const static int WIDTH = 130, //! Rough width for the base of the candle
          WIDTH_TOLERANCE = 35, //! Tolerance for detecting the width of the candle base
          RADIUS_TOLERANCE = 50, //! s
          MIN_SPIKE = 300, //! Minimum difference between two lidar points for them to be a 'spike'
          MAX_SPIKE = 3000; //! Maximum difference between two lidar points for them to be a 'spike'

    const static float VALID_CANDLE_THRESHOLD;

};
