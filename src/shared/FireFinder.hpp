#pragma once

#include <Servo.h>

class FireFinder {

  public:

    void setup();

    void startScan();

    /** looks directly in front for a candle
     * THIS METHOD IS BLOCKING!
     */
    bool seesCandle();

    int watch(int dToCandle);

  private:

    Servo head;

    int minIntensity = 1024,
        sum = 0,
        minPosition = 180,
        position = 0;


    bool scanning = false;

    long timeToChangeAngle = 0l,
         sweepTime = 5000l,
         step = 3;

    const static int MOTOR_PIN = 10,
          SENSOR_PIN = 0,
          MAX_HEAD_ANGLE = 20,
          MIN_HEAD_ANGLE = -35,
          SAMPLE_SIZE = 10,
          SENSOR_HEIGHT = 210,
          INTENSITY_THRESHOLD = 35,
          MIN_INTENSITY = 985;
};
