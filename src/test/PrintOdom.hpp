#pragma once

#include "../MainSketch.hpp"
#include "../shared/Odom.hpp"
#include "../shared/Point.hpp"

class PrintOdom : public MainSketch {
  public:
    void setup();
    void loop();

  private:
    typedef Encoder<2,3> LeftEnc;
    typedef Encoder<18,19> RightEnc;
    Odom<LeftEnc, RightEnc> odom;
};
