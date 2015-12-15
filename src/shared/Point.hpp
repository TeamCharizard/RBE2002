#pragma once
#include <math.h>

/**
 * \brief Represents a point in 2 dimensional space
 */
template<typename T>
class Point {
private:
    T x_,y_;
public:
    /**
     * \breif Default construct with x and y = 0
     */
    Point() : x_(0), y_(0){
    }

    /**
     * \brief Construct with specified x and y values
     */
    Point(T x, T y) : x_(x), y_(y) {
    }

    /**
     * \brief return a new point rotated about the origin by the given angle.
     * \param angle the angle to rotate by.
     * \return the rotated point
     */
    Point<T> rotate(float angle){ return Point<T>(cos(angle)*x()-sin(angle)*y(), sin(angle)*x()+cos(angle)*y()); }

    /**
     * \brief return a new point translated by the given point
     * \param p the point to translate by
     * \return the translated point
     */
    Point<T> translate(Point p){ return Point<T>(x()+p.x(), y()+p.y()); }

    /**
     * \brief Find the distance between two points
     * \param p the other point
     * \return the distance between this point and p
     */
    float distanceTo(Point p) {
      return sqrt(pow(x()-p.x(), 2)+pow(y()-p.y(),2));
    }

    /**
     * \brief Accessor for x.
     */
    T& x() { return x_; }

    /**
     * \brief Accessor for y.
     */
    T& y() { return y_; }
};
