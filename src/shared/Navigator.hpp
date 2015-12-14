#pragma once
#include "Point.hpp"
#include "PID.hpp"

class Navigator {
public:
  Navigator();
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
  PID distPid;
  float angle, distance;
  enum State { TURNING, DRIVING } state;
};
