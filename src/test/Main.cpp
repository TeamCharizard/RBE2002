#include "Main.hpp"
#include <math.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void driveUntilCandle::setup(){
  left.setup(5);
  right.setup(6);
  lidar.setup();
  Odom.setup();
}

void driveUntilCandle::avoidInFront(int distance){
  if (distance < 600 && distance > 0){
    left.set(100);
    right.set(100);
  }
  else {
    left.set(-100);
    right.set(100);
  }
}

void driveUntilCandle::loop(){
    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;

      if (!stop){
        avoidInFront(distances[0]);
      }

      if (cd.detect(candleDistance, candleAngle, distances)){
        count++;
        // Only stop and report that a candle is found once
        // the candle has been detected multiple times.
        // (otherwise sometimes I think the robot will detect it,
        // stop, jerk back a bit and no longer detect the candle)

        if(count > 4) {
          stop = true;
          left.set(0);
          right.set(0);
        }
        else if (count > 8){
          break;
        }
      }
    }
    odom.updateDifferential();
  }

/*
  float angle = (360-candleAngle)*M_PI/180;
  float distance = candleDistance/25.4+1.0;
  printf("Distance=%f, angle=%f\n", distance, angle);
  //Point<float> candlePos(distance*cos(angle), distance*sin(angle));
  Point<float> candlePos(distance, 0.0);
  candlePos = candlePos.rotate(angle);
  printf("Candle_R = (%f, %f)\n", candlePos.x(), candlePos.y());
  candlePos = odom.robotToWorld(candlePos);
  printf("Candle_W = (%f, %f)\n", candlePos.x(), candlePos.y());
  printf("Robot_W = (%f, %f)\n", odom.getPos().x(), odom.getPos().y());
  printf("Robot_dir = %f\n", odom.dir);

  printf("CANDLE FOUND! At x=%f, y=%f\n", candlePos.x(), candlePos.y());
*/
}
