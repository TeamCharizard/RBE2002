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

    /** making these public so other subsystems (candle) */
    Lidar lidar;
    PIDBase base;

  private:

    /** constructor is private because it's a singleton class */
    Robot();
    static Robot *instance;

    DriveDirection driveDirection;
    CandleDetector detector;
    FireFinder ff;

    int *distances;
    int distanceToCandle;
    int angleToCandle;
    
    int candleHeight_mm;
    bool scanning;
    const static int GOAL_DISTANCE = 300;
};
