#pragma once
/** \bried
 *  Houses state machine for searching for the candle
 *  */
#include "Point.hpp"
#include "DriveMotor.hpp"
#include "Lidar.hpp"

class Searcher {
  private:
    enum CheckState {
      THINKING,
      FOUND,
      MISTAKEN,
    };

  public:
    /* \brief
     * Sets state to Searching
     * */
    Searcher();

    /** \brief
     * Creates the lookup table  of lidar distances to guarantee a safe path
     * */
    void setup();

    /** \brief
     * Drives around the field and avoids obstacles in front
     * Always turns 90 degrees away from obstacles.
     * */
    DriveDirection driveAndAvoid();

    /** \brief
     *  Stops driving and double checks candle
     *  */
    CheckState check();

    /** \brief
     * Searches for candle
     * If the robot needs to turn, pushes the location onto the stack for returning
     * Returns true when it sees a candle
     * */
    bool search();

    /* \brief
     * Goes through lookup table of lidar distances
     * if a radius is less than the threshold
     * return the threshold minus actual radius
     * */
    int checkPath();

    /** \brief
     * Turns the angle to the found candle
     * */
    bool turnToFaceCandle();
    /*
     *
    bool driveToCandle();
*/

    /** \brief
     * Runs the main state machine for searching
     * */
    bool run();

    /** \brief
     * Samples lidar data at a given angle over a certain window
     * default window is +/-15 degrees
     *  */
    int minInSample(int i, int ss = 15);

  private:

    int R_TH[360];

    /** \brief
     * The states of the state machine
     * */
    enum State {
      SEARCHING,
      TURNING,
      CHECK_PATH,
      SCOOT,
      CHECKING,
      CHECK_AFTER_SCOOT,
      GO_TO_CANDLE,
      CHECK_FINAL,
      TURN_TO_CANDLE
    };

    /** \brief
     * Names of States to display on LCD
     * */
    const char *stateNames[9] = {
      "SEARCHNG        ",
      "TURNNG          ",
      "CHECK_PATH      ",
      "SCOOT           ",
      "CHECKNG         ",
      "CHECK_AFTR_SCOOT",
      "GO_TO_CANDLE    ",
      "CHECK_FINAL     ",
      "TURN_TO_CANDLE  "
    };

    void changeState(State state);

    /** \brief
     * state variable */
    State state;

    /** \brief
     * timer variable */
    long lastUpdateTime = 0;

    /** \brief
     * The Point the robot is going toward */
    Point<float> goalPoint;

    /** \brief
     * Turning angles */
    float absoluteTurnGoalAngle,
          absoluteCandleAngle;

    /** \brief
     * Counts of sweeps and candles */
    int candleCount = 0,
        sweeps = 0;

    /** \brief
     * Timer lengths */
    const static int AVOID_DISTANCE = 400;
    const static float AVOID_TURN_ANGLE;
};
