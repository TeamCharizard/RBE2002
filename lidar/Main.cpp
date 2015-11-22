#include "Lidar.hpp"
#include "DriveMotor.hpp"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

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
  while (true) {
    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;

      if (distances[0] < 600 && distances[0] > 0){
        left.set(50);
        right.set(50);
      }
      else {
        left.set(-50);
        right.set(50);
      }
    }

  }
}
