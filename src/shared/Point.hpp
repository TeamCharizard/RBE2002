#pragma once
#include <math.h>

template<typename T>
class Point {
private:
    T x_,y_;
public:
    Point() : x_(0), y_(0){
    }

    Point(T x, T y) : x_(x), y_(y) {
    }

    Point<T> rotate(float angle){ return Point<T>(cos(angle)*x()-sin(angle)*y(), sin(angle)*x()+cos(angle)*y()); }
    Point<T> translate(Point p){ return Point<T>(x()+p.x(), y()+p.y()); }
    float distanceTo(Point p) {
      return sqrt(pow(x()-p.x(), 2)+pow(y()-p.y(),2));
    }

    T& x() { return x_; }
    T& y() { return y_; }
};
