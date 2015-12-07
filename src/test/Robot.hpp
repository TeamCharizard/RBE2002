#pragma once


#include "MainSketch.hpp"
#include "../shared/Lidar.hpp"
#include "../shared/CandleDetector.hpp"
#include "../shared/DriveMotor.hpp"
#include "../shared/Search.hpp"
#include "../shared/Odom.hpp"

class Robot {
    public:
        static Robot *getInstance();

        void drive(DriveDirection dir);

        bool search();
        bool driveToCandle();
        bool findCandleHeight();
        bool extinguishCandle();
        bool returnToOrigin();

    private:
        Robot();
        Searcher searcher;
        Lidar lidar;
        DriveMotor left;
        DriveMotor right;
        typedef Encoder<2,3> LeftEnc;
        typedef Encoder<18,19> RightEnc;
        Odom<LeftEnc, RightEnc> odom;
        int *distances;
        static Robot *instance;

};
