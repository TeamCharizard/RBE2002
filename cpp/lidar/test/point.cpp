#include "Lidar.hpp"
#include "CandleDetector.hpp"
#include "DriveMotor.hpp"
#include <signal.h>
#include <stdio.h>
#include <cmath>

Lidar lidar;
DriveMotor left(6);
DriveMotor right(5);

void turnToFace(int angle){
  //turn so that angle will become zero
  int power = 25;
  if (std::abs(angle < 10)){
    left.set(0);
    right.set(0);
  }
  if (angle > 180){
    left.set(power);
    right.set(power);
  }
  else {
    left.set(-power);
    right.set(-power);
  }
}

void my_handler(int s){
  left.set(0);
  right.set(0);
  exit(1);
}

int main(int argc, char **argv){
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);

  int *distances;
  CandleDetector cd;

  while (true) {
    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;

      int candleLocation = cd.detect(distances);
      printf("LOCATION = %d\n", candleLocation);

      //turn to face that angle
      turnToFace(candleLocation);
    }
  }
}
