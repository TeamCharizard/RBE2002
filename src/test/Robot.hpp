#pragma once

#include "MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/Searcher.hpp"
#include "../shared/PIDBase.hpp"
#include "../shared/FireFinder.hpp"

class Robot {
  public:
    static Robot *getInstance();

    void setup();

    void drive();

    void stop();

    /** given a direction, set the motor PIDs accordingly
     * @param dir the direction you want to go
     */
    void setDrive(DriveDirection dir);

    /** search for candle by driving around
     * @return true when the candle has been found
     */
    bool search();

    bool driveToCandle();

    bool findCandleHeight();

    bool extinguishCandle();

    bool returnToOrigin();

    bool turnToFace(int angle);

    void driveAndAvoid();
  private:

    /** constructor is private because it's a singleton class */
    Robot();

    Searcher searcher;
    Lidar lidar;
    DriveDirection driveDirection;
    CandleDetector detector;
    FireFinder ff;
    PIDBase base;
    int *distances;
    static Robot *instance;
    int distanceToCandle;
    const int GOAL_DISTANCE = 300;
    int angleToCandle;
};
