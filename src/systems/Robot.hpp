#pragma once

#include "Lidar.hpp"

class Robot {

  public:

    enum Mode {
      LIDAR,
      ODOM,
      NOTHING
    };

    /** constructor is private because it's a singleton class */
    Robot();

    static Robot *getInstance();

    /** \brief calls setup of other systems */
    static void setup();

    /** \brief returns current mode
     * @return the current mode
     */
    static Mode getMode();

    /** \brief sets new mode
     * @param mode new mode
     */
    static void setMode(Mode mode);

    static Lidar lidar;
    //static PIDBase base;
    //static FireFinder ff;
    //static DriveDirection driveDirection;
    //static Extinguisher extinguisher;
    //static Searcher searcher;
    //static Gyro gyro;
    //static CandleDetector detector;

    //static Stack<Point<float>, 256> path;
    const static int WIDTH = 190;
    const static long ODOM_FREQ = 50;
    static long lastUpdateTime;

  private:

    static Mode mode;

    static Robot *instance;
    const static int GOAL_DISTANCE = 300;


};
