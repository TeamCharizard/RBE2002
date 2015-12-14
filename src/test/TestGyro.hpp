#pragma once

#include "../MainSketch.hpp"
#include "../shared/Gyro.hpp"

class TestGyro : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    Gyro gyro;

};
