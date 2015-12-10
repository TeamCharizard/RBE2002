#pragma once

class CandleDetector{

  public:
    CandleDetector();

    /** Looks for candle and returns true if found
     *  assigns values to given pointers for distance and angle
     *  based on input array of distances
      */
    bool detect(int *distance, int *angle, int *radii);

  private:
    const static int WIDTH = 130,
          WIDTH_TOLERANCE = 35,
          MIN_SPIKE = 300,
          MAX_SPIKE = 3000;

    const static float VALID_CANDLE_THRESHOLD;

};
