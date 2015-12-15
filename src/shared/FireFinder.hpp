#pragma once

#include <Servo.h>

/** \brief Wrapper around head servo,
 * and contains functions for scanning for fire and reporting candle height */
class FireFinder {

  public:

    /** \brief setup the head servo */
    void setup();

    /** \brief sets some flags to start scanning for candle.
     * This doesn't actually do any scanning, you have to be callling watch */
    void startScan();

    /** \brief Looks directly in front for a candle by sampling IR.
     */
    bool seesCandle();

    /** \brief Call this continuously to check candle height.
     * \return 0 for not finish, -1 for no candle, and positive for the candle height
     */
    float watch(int dToCandle);

    /** \brief Simply set the head to 90 degrees */
    void levelHead();

  private:

    /** \brief The motor object */
    Servo head;

    /** \brief min intensity during scan */
    int minIntensity = 1024;

    /** \brief min position during scan */
    int minPosition = 100;

    /** \brief Current position of head during scan */
    int position = 0;

    /** \brief The current state of the scanning routine */
    bool scanning = false;

    /** \brief Controls the speed of sweeping. */
    long timeToChangeAngle = 0l;
    long sweepTime = 5000l;
    long step = 3;

    const static int MOTOR_PIN = 10;
    const static int SENSOR_PIN = 0;
    const static int MAX_HEAD_ANGLE = 20;
    const static int MIN_HEAD_ANGLE = -35;
    const static int SAMPLE_SIZE = 10;
    const static int SENSOR_HEIGHT = 210;
    const static int INTENSITY_THRESHOLD = 35;
    const static int MIN_INTENSITY = 995;
};
