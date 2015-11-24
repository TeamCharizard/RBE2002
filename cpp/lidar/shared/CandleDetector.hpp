#pragma once

class CandleDetector{

  public:
    CandleDetector();

    /** looks are 360deg array and finds candles.
      * If no candle is found, it returns 0
      * If a candle is found, it returns the degree of it's location
      */
    int detect(int radii[]);

  private:
    const static int WIDTH = 100,
          WIDTH_TOLERANCE = 30,
          MIN_SPIKE = 300,
          MAX_SPIKE = 450;

};
