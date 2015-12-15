#pragma once

#include "MainSketch.hpp"
#include "shared/Lidar.hpp"
#include "shared/Gyro.hpp"
#include "shared/CandleDetector.hpp"
#include "shared/Extinguisher.hpp"
#include "shared/Searcher.hpp"
#include "shared/PIDBase.hpp"
#include "shared/FireFinder.hpp"
#include "shared/Stack.hpp"
#include "shared/Navigator.hpp"

class Robot {
  public:
    /** \brief singleton accessor for robot instance.
     * Using a singleton makes sense because only one robot exists,
     * and everyone can access it statically
     */
    static Robot *getInstance();

    /** \brief calls setups for all subsystems */
    void setup();

    /** \brief sets the velocity of PIDBase to 0.
     * This won't nessecarily stop the robot unless you're calling base.drive
     */
    void stop();

    /** \brief genuinely stops the motors. It simply writes 90 to both motors.
     * Don't use this if you can avoid it, it can jerk the robot around.
     */
    void hardStop();

    /** given a direction, set the motor PIDs accordingly
     * @param dir the direction you want to go
     */
    void setDrive(DriveDirection dir);

    /** \brief search for candle by driving around
     * \return true when the candle has been found
     */
    bool search();

    /** \brief calls out to FireFinder to determine the height of the candle
     * \return whether the height of the candle has been determinued
     */
    bool findCandleHeight();

    /** \brief calls the sub-state machine to extinguish the candl
     * \return whether the candle is extinguished yet
     */
    bool extinguishCandle();

    /** \brief Returns robot to origin. Pops all the Points pushed on to the stack and traverses them.
     * \return whether the robot has returned to origin yet
     */
    bool returnToOrigin();

    /** \brief The end routine. Stops the robot and prints final info */
    void end();

    /** \brief set the goal for navigator to a delta in the candle frame
     * candle frame is centered at the robot, but with x towards the candle
     * \param delta the x and y displacement in candle frame
     */
    void setGoalInCandleFrame(Point<float> delta);

    /** \brief set the goal for navigator to the current position of the candle,
     * minus a constant CANDLE_APPROACH_DISTANCE_INCHES.
     * This is based on the last known location of the candle in the world frame.
     */
    void setGoalToCandle();

    /** \brief gets the last known angle to the candle in current robot frame
     * \return last known angle to candle in current robot frame
     */
    float absoluteCandleAngleFromCurrentPosition();

    /** \brief gets the last known absolute position of the candle
     * and sets it as final in status manager
     */
    void setFinalAbsoluteCandlePosition();

    /** \brief pushes the current position of the robot on to the stack.
     * This allows us to reverse out path to the candle.
     * Call this every time the robot has significantly changed it's position
     */
    void pushPos();

    /** \brief pops a waypoint off the stack and sets it as the current goal in navigator */
    void popWaypoint();

    /** \brief uses PIDBase to turn to face an angle in the world frame
     * \return whether the robot has reached it's goal angle
     */
    bool turnToFaceAbsolutely(float angle);

    /** \brief blink LED eyes for 1 second */
    void blink();
    // making these public so other subsystems

    /** \brief lidar subsystem */
    Lidar lidar;

    /** \brief PID drive base subsystem */
    PIDBase base;

    /** \brief fire finder subsystem */
    FireFinder ff;

    /** \brief cande detector subsystem */
    CandleDetector detector;

    /** \brief navigator subsystem */
    Navigator navigator;

    /** \brief Stack for the navigation waypoints */
    Stack<Point<float>, 256> path;

    /** \brief distance at which we blow out candle */
    const static int CANDLE_APPROACH_DISTANCE_INCHES = 30;

    /** \brief WIDTH of half the robot plus a little bit to give some */
    const static int WIDTH = 205;

    /** \brief the period at which we update odometry */
    const static long UPDATE_PERIOD = 270;

  private:

    /** \brief constructor is private because it's a singleton class */
    Robot();

    /** \brief static instance of robot */
    static Robot *instance;

    /** \brief drive direction enum */
    DriveDirection driveDirection;

    /** \brief extinguisher instance. Controls the extinguish routine */
    Extinguisher extinguisher;

    /** \brief searcher instance. Controls the search routine */
    Searcher searcher;

    /** \brief gyro for getting points */
    Gyro gyro;

    /** \brief variable for determining when we're scanning for candle height */
    bool scanning = false;

    /** \brief the current waypoint we're navigating to */
    Point<float> waypoint;

    /** \brief stores the last time for the odometry loop */
    long lastUpdateTime = 0;
};
