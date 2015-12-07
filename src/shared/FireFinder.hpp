#pragma once

#include <Servo.h>

class FireFinder {

  public:

    FireFinder();

    void setup();

    void startScan();

    int watch(int dToCandle);

  private:

    Servo head;

    int minIntensity = 1024,
        minPosition = 180,
        position = 0;

    bool scanning = false;

    const static int MOTOR_PIN = 10,
          SENSOR_PIN = 0,
          MAX_HEAD_ANGLE = 65,
          MIN_HEAD_ANGLE = 30,
          SENSOR_HEIGHT = 190;
};
