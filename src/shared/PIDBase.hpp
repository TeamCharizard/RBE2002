#pragma once

#include "Encoder.hpp"
#include "Odom.hpp"
#include "DriveMotor.hpp"
#include "PID.hpp"

/** \brief contains PIDs for controlling the turning and driving of the robot.
 * You can turn to a specific angle, drive straight with a speed,
 * or turn at a speed.
 */
class PIDBase {
  public:
    PIDBase();
    void setup();
    float drive();
    void setSpeeds(int leftSpeed, int rightSpeed);
    void stop();
    void hardStop();
    float x();
    float y();
    Point<float> pos();
    float dir();
    bool turnAbsolutely(float direction);
    typedef Encoder<2,3> RightEnc;
    typedef Encoder<18,19> LeftEnc;
    Odom<LeftEnc, RightEnc> odom;
    bool stopped();
  private:
    // Normalize an angle to 0 to 360
    float normalize(float angle);

    /** scaled input from (-10,10) to (-TOP_SPEED, TOP_SPEED)
     * @param speed the input speed from -10 to 10
     */
    int scale(int speed);

    DriveMotor lMotor,rMotor;
    PID lPID,rPID,dirPID;
    const int TOP_SPEED = 50; //ticks per UPDATE_PERIOD
};
