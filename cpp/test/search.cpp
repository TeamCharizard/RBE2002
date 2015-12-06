#include "DriveMotor.hpp"
#include "Lidar.hpp"
#include <stdio.h>
#include <signal.h>
#include <iostream>
#include <chrono>

typedef std::chrono::steady_clock steady_clock;
typedef std::chrono::time_point<steady_clock> time_point;

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

  time_point now;
  while (true) {
    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;
      dFront = distances[0];
      dRight = distances[10];
      dLeft = distances[350];
    }

    if (dFront < 500 && dFront > 0 && !turning){
      now = steady_clock::now();
      turning = true;
      printf("starting turn\n");
    }
    else if (!turning) {
      left.set(-50);
      right.set(50);
    }

    if (turning){
      auto timestep = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_update);
      std::cout << "timestep = " << timestep.count() << std::endl;
      if (timestep.count() > 5000){
        printf("done turning\n");
        turning = false;
      }

      if (dRight > dLeft){
        left.set(50);
        right.set(0);
      }
      else {
        left.set(0);
        right.set(50);
      }

      last_update = now;
    }

  }
}
