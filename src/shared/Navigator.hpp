#pragma once
#include "Point.hpp"

class Navigator {
public:
  /**
   * \brief set the goal to drive to 
   * This also resets the internal state
   * \param goal the point to drive to (in world coordinates)
   */
  void setGoal(Point<float> goal);

  /**
   * \brief drive to the point
   * \return true when the drive is complete
   */
  bool run();
private:
  float angle, distance;
  enum State { TURNING, DRIVING } state;
};
