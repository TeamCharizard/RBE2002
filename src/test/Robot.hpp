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
#include "../shared/Navigator.hpp"

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

    void pushPos();

    /** \brief set the goal for navigator to a delta in the candle frame
     * candle frame is centered at the robot, but with x towards the candle
     * \param delta the x and y displacement in candle frame
     */
    void setGoalInCandleFrame(Point<float> delta);

    void setGoalToCandle();

    bool findCandleHeight();

    bool extinguishCandle();

    float absoluteCandleAngle();

    bool returnToOrigin();

    Point<float> absoluteCandlePosition();

    bool turnToFaceAbsolutely(float angle);

    void end();

    /** making these public so other subsystems (candle) */
    Lidar lidar;
    PIDBase base;
    FireFinder ff;
    CandleDetector detector;
    Navigator navigator;
    Stack<Point<float>, 256> path;

    const static int WIDTH = 220;

  private:

    /** constructor is private because it's a singleton class */
    Robot();
    static Robot *instance;

    DriveDirection driveDirection;
    Extinguisher extinguisher;
    Searcher searcher;
    Gyro gyro;

    bool scanning = false;
    const static int CANDLE_APPROACH_DISTANCE_INCHES = 20;

    long lastUpdateTime = 0;
    const static long UPDATE_PERIOD = 50;
};
