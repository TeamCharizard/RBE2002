#include "Geom.hpp"
#include "Encoder.hpp"
#include <chrono>

class Odom {
private:
    typedef std::chrono::steady_clock steady_clock;
    typedef std::chrono::time_point<steady_clock> time_point;
    Encoder enc1, enc2;
    time_point last_update;
    Vec<float> pos;

    constexpr static float wheel_radius = 2.75/2; // inches
    constexpr static float rot_wheel_pos = 3.375; // inches
public:
    Odom(int enc1a, int enc1b, int enc2a, int enc2b);

    float dir;
    Vec<float> update();
};

