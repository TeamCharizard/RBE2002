#pragma once

#include <L3G.h>
#include <Wire.h>

class Gyro {
  public:
    Gyro();
    void setup();

    /** \brief angle of robot
     * \return angle in degrees of robot in world frame */
    int read();

  private:
    /** \brief the gyro duh */
    L3G gyro;

    /** \brief Integration time (DCM algorithm)  We will run the integration loop at 50Hz if possible */
    float G_Dt=0.005;

    /** \brief gyros gain factor for 250deg/sec
     */
    float G_gain=.00875;

    /** \brief gyro x val*/
    float gyro_z;

    /** \brief gyro cummulative z value */
    float gyro_zold;

    /** Gyro 7 error */
    float gerrz;
};
