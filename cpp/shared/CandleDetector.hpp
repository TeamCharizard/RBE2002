#pragma once

class CandleDetector{

  public:
    CandleDetector();

    /** looks are 360deg array and finds candles.
      * If no candle is found, it returns 0
      * If a candle is found, it returns the degree of it's location
      */
    bool detect(int& distance, int& angle, int radii[]);

  private:
    const static int WIDTH = 120,
          WIDTH_TOLERANCE = 60,
          MIN_SPIKE = 200,
          MAX_SPIKE = 1000;

};
