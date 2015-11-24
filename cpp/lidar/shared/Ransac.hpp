#pragma once

#include <list>

class Line{
  public:
    Line() = default;
    Line(const double *xs, const double *ys, int n);
    double slope;
    double intercept;
};

class Ransac{

  private:
    //tuning parameters
    const static int CONSENSUS = 40;
    const static int N = 100;

  public:
    /** return an array of lines you found */
    std::list<Line> run(double *xs, double *ys);

    /** swap two elements in a list */
    void exch(double *points, int i, int j);

    /** given two points (x0,y0) and (x1,y1), find the from the line between them
     * to the point (x2,y2)
     */
    double distFromPointToLine(double x0, double y0, double x1, double y1, double x2, double y2);
};
