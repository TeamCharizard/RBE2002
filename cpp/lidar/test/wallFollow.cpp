#include "Lidar.hpp"
#include "Point.hpp"
#include "CandleDetector.hpp"
#include "DriveMotor.hpp"
#include <signal.h>
#include <stdio.h>
#include <cmath>

Lidar lidar;
DriveMotor left(6);
DriveMotor right(5);

double distFromWall(Point<double> p0, Point<double> p1){
  return std::abs(p0.x() * p0.y() - p0.y() * p1.x())/
    sqrt(pow((p0.y() - p1.y()), 2.0) + pow(p0.x() - p1.x(), 2.0));
}

void turnToFace(int angle){
  //turn so that angle will become zero
  int power = 0;
  double kP = .5;
  if (std::abs(angle < 10)){
    left.set(0);
    right.set(0);
  }
  else if (angle > 180){
    power = (360-angle)*kP;
    left.set(power);
    right.set(power);
  }
  else {
    power = (360-angle)*kP;
    left.set(-power);
    right.set(-power);
  }
}

Point<double> polToCart(double deg, double radius){
  double rad = deg*3.141592653/180;
  Point<double> p;
  p.x() = cos(rad) * radius;
  p.y() = sin(rad) * radius;
}

void my_handler(int s){
  left.set(0);
  right.set(0);
  exit(1);
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

      //int candleLocation = cd.detect(distances);

      int forwardRadius = surroundingAvg(distances, 360, 45);
      int backRadius = surroundingAvg(distances, 360, 135);

      //convert from polar to cartesian
      Point<double> p0;
      Point<double> p1;

      p0 = polToCart(45, forwardRadius);
      p1 = polToCart(135, backRadius);

      double d = distFromWall(p0,p1);
      printf("%d\n",d);


    }
  }
}
