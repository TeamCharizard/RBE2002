#include "DriveUntilCandle.hpp"
#include "../main.hpp"
#include <MemoryFree.h>
#include <math.h>

void DriveUntilCandle::setup(){
  lidar.setup();
  base.setup();
}

void DriveUntilCandle::avoidInFront(int distance){
  if (distance < 500 && distance > 0){
    base.setSpeeds(-10,10);
  }
  else {
    base.setSpeeds(10,10);
  }
}

void DriveUntilCandle::loop(){

  bool fullSweep = lidar.read();

  if (fullSweep){
    Serial.println(freeMemory());
    base.run();
    distances = lidar.distances;

    avoidInFront(distances[0]);

    if (cd.detect(&candleDistance, &candleAngle, distances)){
      count++;

      // Only stop and report that a candle is found once
      // the candle has been detected multiple times.
      // (otherwise sometimes I think the robot will detect it,
      // stop, jerk back a bit and no longer detect the candle)
      char msg[16];
      snprintf(msg,16,"a=%-3d d=%-4d", candleAngle, candleDistance);
      Display.setCursor(0,0);
      Display.print(msg);
      Serial.println(msg);
    }
  }
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
