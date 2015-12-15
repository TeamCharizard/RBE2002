#pragma once
#include "Point.hpp"
#include "Encoder.hpp"
#include "Gyro.hpp"
#include "StatusManager.hpp"
#include "../charizard.hpp"

/**
 * \brief Tracks the robot's position via encoders
 */
template<typename Enc1, typename Enc2>
class Odom {
  private:
    /**
     * \brief Robot's current position in world frame
     */
    Point<float> pos;
    Gyro gyro;

    constexpr static float wheel_radius = 2.75/2; // inches
    constexpr static float rot_wheel_pos = 3.375; // inches

  public:
    Odom() : dir(0.0) {}

    void setup() {
      Enc1::setup();
      Enc2::setup();
      Serial.println("Gyro start");
      gyro.setup();
      Serial.println("Gyro end");
    }

    //! Direction the robot is facing
    float dir, gyroAngle;

    int left_disp,
        right_disp;

    /**
     * \brief update the robots position based on encoder ticks since last update
     * \return distance the robot has traveled forward (since the last update)
     */
    float updateDifferential() {

      left_disp = Enc1::read(true);
      right_disp = Enc2::read(true);

      float rot_disp = (right_disp - left_disp)*M_PI*wheel_radius/(360*7.5/2);
      float disp = (left_disp + right_disp)*M_PI*wheel_radius/360;

      dir -= rot_disp;

      pos.x() += disp*cos(dir);
      pos.y() += disp*sin(dir);

      StatusManager::robotX = pos.x();
      StatusManager::robotY = pos.y();
      StatusManager::robotAngle = gyro.read();
      StatusManager::printPose();

      return disp;
    }

    /**
     * \return get the number of ticks seen by the left encoder from the last update
     */
    int leftDisplacement() {
      return left_disp;
    }

    /**
     * \return get the number of ticks seen by the right encoder from the last update
     */
    int rightDisplacement() {
      return right_disp;
    }

    /**
     * \brief get the lastest robot position
     * \return the lastest robot position
     */
    inline Point<float> getPos() { return pos; }

    /**
     * \brief transform a point from robot frame to world frame
     * \param robotPoint a point the the frame of the robot
     * \return the input point trasnformed to world frame
     */
    Point<float> robotToWorld(Point<float> robotPoint) {
      return robotPoint.rotate(dir).translate(pos);
    }
};

