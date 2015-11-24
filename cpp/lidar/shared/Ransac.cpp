#include "Ransac.hpp"
#include <math.h>
#include <cmath>
#include <stdio.h>
#include "gsl/gsl_fit.h"
#include <stdlib.h> //no I'm not going to bother seeding...

Line::Line(const double *x, const double *y, int n){
  double slope,intercept, ccv00, ccv01, ccv11, sumsq;
  gsl_fit_linear(x, 1, y, 1, n, &slope, &intercept, &ccv00, &ccv01, &ccv11, &sumsq);
  this->slope = slope;
  this->intercept = intercept;
}

void Ransac::exch(double *points, int i, int j){
  double tmp = points[i];
  points[i] = points[j];
  points[j] = tmp;
}

double Ransac::distFromPointToLine(double x0, double y0, double x1, double y1, double x2, double y2){
  return std::abs((y0 - y1) * x2 - (x0 - x1) * y2 + x0 * y1 - y0 * x1)/
    sqrt(pow((y0 - y1), 2.0) + pow(x0 - x1, 2.0));
}

std::list<Line> Ransac::run(double *xs, double *ys){
  std::list<Line> lines;

  //remove shit data
  for (int i=0;i<360;i++){
    double radius = sqrt(xs[i]*xs[i] + ys[i]*ys[i]);
    if (radius < 80) {
      xs[i] = -1;
      ys[i] = -1;
    }
  }

  int hi = 360;
  int in = 0;
  int maxIn = 0;

  double x0,x1,y0,y1;

  double xInliers[360];
  double yInliers[360];
  double inlierIndeces[30];

  for (int n = 0; n < N && hi > 0; n++){
    //start off at 2 so we have room for the x0,y0 and x1,y1
    in = 2;

    //Choose a sample of 2 points uniformly at random
    int r1 = rand()%360;
    int r2 = rand()%360;
    x0 = xs[r1];
    x1 = xs[r2];
    y0 = ys[r1];
    y1 = ys[r2];

    //find distance of other points to line between those two points
    //and construct the inlier set
    printf("considering %d points on trial %d\n",hi,n);
    for (int i=0;i<hi;i++){

      double x2 = xs[i],
             y2 = ys[i];

      //we ignore data that's impossibly close
      if (x2 > 0 && y2 > 0){

        double dist = distFromPointToLine(x0,y0,x1,y1,x2,y2);

        if (dist < 10){
          if (in < 360){
            xInliers[in] = x2;
            yInliers[in] = y2;
            inlierIndeces[in] = i;
            in++;
          }
        }
      }
    }

    if (in > maxIn){
      maxIn = in;
    }

    //If there are enough inliers, recompute the line parameters, store the line, remove the inliers from the set
    if (maxIn > CONSENSUS){
      xInliers[0] = x0;
      yInliers[0] = y0;
      xInliers[1] = x1;
      yInliers[1] = y1;
      Line l(xInliers, yInliers, in);
      lines.push_back(l);

      //remove the inliners!
      //we do this by exchanging all the inliners to the end, and lowering hi
      printf("removing %d pts\n",maxIn);
      for (int i=0;i<maxIn;i++){
        exch(xs, inlierIndeces[i],hi--);
      }

    }

  }

  return lines;
}
