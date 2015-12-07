#pragma once
#include "Point.hpp"
#include "Encoder.hpp"

template<typename Enc1, typename Enc2>
class Odom {
private:
    Point<float> pos;

    constexpr static float wheel_radius = 2.75/2; // inches
    constexpr static float rot_wheel_pos = 3.375; // inches
public:
    Odom() : dir(0.0) {}

    void setup() {
        Enc1::setup();
        Enc2::setup();
    }

    float dir;
    void update();

    void updateDifferential() {
        int left_disp = Enc1::read(true);
        int right_disp = Enc2::read(true);

        float rot_disp = (right_disp - left_disp)*M_PI*wheel_radius/(360*7.5/2);
        float disp = (left_disp + right_disp)*M_PI*wheel_radius/360;

        dir += rot_disp;

        pos.x() += disp*cos(dir);
        pos.y() += disp*sin(dir);
    }

    inline Point<float> getPos() { return pos; }

    Point<float> robotToWorld(Point<float> robotPoint) {
        return robotPoint.rotate(dir).translate(pos);
    }
};

