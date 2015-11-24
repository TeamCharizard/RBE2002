#include "Lidar.hpp"
#include "CandleDetector.hpp"
#include "DriveMotor.hpp"
#include <math.h>
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
    left.set(100);
    right.set(100);
  }
  else {
    left.set(-100);
    right.set(100);
  }
}

void avoidAllAround(int d0, int dLeft, int dRight){
  int min = 500;
  if (d0 < min && d0 > 0){
    left.set(100);
    right.set(100);
  }
  else if (dRight < min && dRight > 0){
    left.set(-100);
    right.set(-100);
  }
  else if (dLeft < min && dLeft > 0){
    left.set(100);
    right.set(100);
  }
  else {
    left.set(-100);
    right.set(100);
  }
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

  while (true) {
    bool fullSweep = lidar.read();

    if (fullSweep){
      distances = lidar.distances;

      int candleLocation = cd.detect(distances);
    }
  }
}
