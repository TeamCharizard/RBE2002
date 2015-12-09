#pragma once

#include "MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/PID.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/Searcher.hpp"
#include "../shared/Odom.hpp"

class Robot {
    public:
        static Robot *getInstance();

        void setup();

        void drive();

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
        Robot();
        Searcher searcher;
        Lidar lidar;
        DriveMotor left;
        DriveMotor right;
        typedef Encoder<2,3> LeftEnc;
        typedef Encoder<18,19> RightEnc;
        Odom<LeftEnc, RightEnc> odom;
        DriveDirection driveDirection;
        int *distances;
        static Robot *instance;
        CandleDetector detector;
        int distanceToCandle;
        const int GOAL_DISTANCE = 300;
        int angleToCandle;
};
