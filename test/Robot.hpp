#pragma once

#include "MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/Gyro.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/Extinguisher.hpp"
#include "../shared/Searcher.hpp"
#include "../shared/PIDBase.hpp"
#include "../shared/FireFinder.hpp"
#include "../shared/Stack.hpp"

class Robot {
  public:
    static Robot *getInstance();

    void setup();

    void stop();

    /** given a direction, set the motor PIDs accordingly
     * @param dir the direction you want to go
     */
    void setDrive(DriveDirection dir);

    /** search for candle by driving around
     * @return true when the candle has been found
     */
    bool search();

    bool findCandleHeight();

    bool extinguishCandle();

    bool returnToOrigin();

    bool turnToFaceAbsolutely(float angle);

    /** making these public so other subsystems (candle) */
    Lidar lidar;
    PIDBase base;
    FireFinder ff;
    CandleDetector detector;
    Stack<Point<float>, 256> path;

    const static int WIDTH = 190;

  private:

    /** constructor is private because it's a singleton class */
    Robot();
    static Robot *instance;

    DriveDirection driveDirection;
    Extinguisher extinguisher;
    Searcher searcher;
    Gyro gyro;

    bool scanning = false;
    const static int GOAL_DISTANCE = 300;

    long lastUpdateTime = 0;
    const static long UPDATE_PERIOD = 50;
};
