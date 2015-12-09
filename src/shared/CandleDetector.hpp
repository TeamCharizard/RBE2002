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
    const static int WIDTH = 120,
          WIDTH_TOLERANCE = 60,
          MIN_SPIKE = 200,
          MAX_SPIKE = 1000;

};
