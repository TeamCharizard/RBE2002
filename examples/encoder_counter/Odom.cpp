#include "Odom.hpp"
#include <iostream>
#include <math.h>

Odom::Odom(int enc1a, int enc1b, int enc2a, int enc2b) :
  enc1(enc1a, enc1b), enc2(enc2a, enc2b), dir(0.0),
  last_update(steady_clock::now())
{ pos.x() = 0.0; pos.y() = 0.0; }

Vec<float> Odom::update() {
    time_point now = steady_clock::now();
    auto timestep = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_update);

    int rot_counts = enc1.read(true);
    int disp_counts = enc2.read(true);



    float disp = disp_counts*2*M_PI*wheel_radius/360;
    float rot_disp = rot_counts*2*M_PI*wheel_radius/(360*rot_wheel_pos);

    dir += rot_disp;

    pos.x() += disp*cos(dir);
    pos.y() += disp*sin(dir);

    last_update = now;
    return pos;
}

int main(int argc, char** argv) {
    Odom odom(11, 8, 4, 2);
    while(true) {
        usleep(50000);
        auto pos = odom.update();
        printf("(%f, %f), %f\n", pos.x(), pos.y(), odom.dir);
    }
}
