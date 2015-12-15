#pragma once

#include "Point.hpp"

/** \brief Contains methods for detecting candle and storing its location */
class CandleDetector{

  public:

    /** Looks for candle and returns true if found.
     * Gets lidar data from Robot.
     * Iterates over data and if two spikes in data are found
     * and they are right distance apart, return true
     * \return whether a candle has been found. It's location is then available in distance() and angle()
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

    /** \brief Internal variables for candle location */
    int candleDistance = 0,
        candleAngle = 0;

    /** \brief The width of the candle block in mm */
    const static int WIDTH = 130;

    /** \brief Tolerance for the with of the candle block in mm */
    const static int WIDTH_TOLERANCE = 35;

    /** \brief The max difference between the distance of two edge of the candle block in mm */
    const static int RADIUS_TOLERANCE = 50;

    /** \brief the minimum difference between candle block and a wall in mm */
    const static int MIN_SPIKE = 300;

    /** \brief the maximum distanc between a candle block and a wall in mm */
    const static int MAX_SPIKE = 3000;

    /** \brief the percentage of valid data required between two spikes to
     * consider it a candle */
    const static float VALID_CANDLE_THRESHOLD;

};
