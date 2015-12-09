#pragma once

#include "MainSketch.hpp"
#include "../main.hpp"
#include "../shared/Encoder.hpp"
#include "../shared/Odom.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/PID.hpp"

class PIDTest : public MainSketch {
  public:
    PIDTest();
    void loop();
    void setup();

  private:
    DriveMotor lMotor,rMotor;
    typedef Encoder<2,3> LeftEnc;
    typedef Encoder<18,19> RightEnc;
    Odom<LeftEnc, RightEnc> odom;
    PID lPID,rPID;
    long lastUpdate;
    const long UPDATE_PERIOD = 100;
};
