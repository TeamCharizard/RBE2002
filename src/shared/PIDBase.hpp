#pragma once

#include "Encoder.hpp"
#include "Odom.hpp"
#include "DriveMotor.hpp"
#include "PID.hpp"

class PIDBase {
  public:
    PIDBase();
    void setup();
    void drive();
    void setSpeeds(int leftSpeed, int rightSpeed);
    void stop();
    float x();
    float y();
    float dir();
    bool turnAbsolutely(float direction);

  private:

    /** scaled input from (-10,10) to (-TOP_SPEED, TOP_SPEED)
     * @param speed the input speed from -10 to 10
     */
    int scale(int speed);

    DriveMotor lMotor,rMotor;
    typedef Encoder<2,3> RightEnc;
    typedef Encoder<18,19> LeftEnc;
    Odom<LeftEnc, RightEnc> odom;
    PID lPID,rPID,dirPID;
    long lastUpdate;
    const long UPDATE_PERIOD = 200; //milliseconds
    const int TOP_SPEED = 35; //ticks per UPDATE_PERIOD
};
