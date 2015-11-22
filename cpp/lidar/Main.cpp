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

void avoidInFront(int distance){
  if (distance < 600 && distance > 0){
    left.set(50);
    right.set(50);
  }
  else {
    left.set(-50);
    right.set(50);
  }
}

void avoidAllAround(int d0, int dLeft, int dRight){
  int min = 300;
  printf("%d, %d, %d\n", dLeft, d0, dRight);
  if (d0 < min && d0 > 0){
    left.set(50);
    right.set(50);
  }
  else if (dRight < min && dRight > 0){
    left.set(-50);
    right.set(50);
  }
  else if (dLeft < min && dLeft > 0){
    left.set(50);
    right.set(-50);
  }
  else {
    left.set(-50);
    right.set(50);
  }
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
      int c=0;
      for (int i=0;i<360;i++){
        if (distances[i] == -1) {
          c++;
        }
      }
      //avoidAllAround(distances[0], distances[90], distances[270]);

      //avoidInFront(distances[0]);

    }

  }
}
