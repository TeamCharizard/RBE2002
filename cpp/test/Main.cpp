#include "Lidar.hpp"
#include "CandleDetector.hpp"
#include "DriveMotor.hpp"
#include "Odom.hpp"
#include <math.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

Lidar lidar;

DriveMotor left(6);
DriveMotor right(5);
Odom odom(12, 13, 8, 11);

void my_handler(int s){
  left.set(0);
  right.set(0);
  exit(1);
}

void avoidInFront(int distance){
  if (distance < 600 && distance > 0){
    left.set(100);
    right.set(100);
  }
  else {
    left.set(-100);
    right.set(100);
  }
}

void avoidAllAround(int d0, int dLeft, int dRight){
  int min = 300;
  if (d0 < min && d0 > 0){
    left.set(100);
    right.set(100);
  }
  else if (dRight < min && dRight > 0){
    left.set(100);
    right.set(100);
  }
  else if (dLeft < min && dLeft > 0){
    left.set(-100);
    right.set(-100);
  }
  else {
    left.set(-100);
    right.set(100);
  }
}

int wallFollow(int front, int back){

}

int mod(int a, int b){
  int r = a % b;
  return r < 0 ? r + b : r;
}

int surroundingAvg(int *arr, int len, int i){
  int s = 30;
  int min = mod((i - s), len);
  int max = mod((i + s), len);
  int sum=0;
  for (int j=min; j!=max; j = (j+1)%len){
    sum += arr[j];
  }
  int avg = sum/(s * 2);
  return avg;
}

int main(int argc, char **argv){
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);

  int *distances;
  CandleDetector cd;

  int candleAngle = 0;
  int candleDistance = 0;
  int count = 0;
  while (true) {

    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;
      printf("d0=%d\n",distances[0]);
      avoidInFront(distances[0]);

      if (cd.detect(candleDistance, candleAngle, distances)){
        count++;
        // Only stop and report that a candle is found once
        // the candle has been detected multiple times.
        // (otherwise sometimes I think the robot will detect it,
        // stop, jerk back a bit and no longer detect the candle)
        if(count > 4) {
          break;
        }
      }
    }
    odom.updateDifferential();
  }
  left.set(0);
  right.set(0);

  count = 0;
  while (true) {

    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;
      printf("d0=%d\n",distances[0]);
      if (cd.detect(candleDistance, candleAngle, distances)){
        count++;
        // Wait until we've detected the candle 5 times
        // (this will ensure that we have come to a complete stop)
        if(count > 5) {
        break;
        }
      }
    }
    odom.updateDifferential();
  }

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
}
