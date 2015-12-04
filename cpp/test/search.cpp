#include "DriveMotor.hpp"
#include "Lidar.hpp"
#include <stdio.h>
#include <signal.h>

Lidar lidar;
DriveMotor left(6);
DriveMotor right(5);

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
  bool turning = false;
  int dFront, dRight, dLeft;
  time_point last_update;

  while (true) {
    time_point now = steady_clock::now();
    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;
      dFront = distances[0];
      dRight = distances[10];
      dLeft = distances[350];
    }

    printf("dFront=%d dRight=%d dLeft=%d\n",dFront,dRight,dLeft);

    if (dFront < 400 && dFront > 0){
      turning = true;
    }
    else if (!turning) {
      left.set(-50);
      right.set(50);

    }

    if (turning){
      auto timestep = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_update);
      if (timestep > 1000){
        turning = false;
      }
      if (dRight > dLeft){
        //turn right
        left.set(100);
        right.set(0);
      }
      else {
        //turn left
        left.set(0);
        right.set(100);
      }
    }

    last_update = now;
  }
}
