#include "Odom.hpp"
#include "Point.hpp"
#include <iostream>

int main(int argc, char** argv) {
    Odom odom(12, 13, 8, 11);
    while(true) {
        usleep(50000);
        auto pos = odom.updateDifferential();
        printf("(%f, %f), %f\n", pos.x(), pos.y(), odom.dir);
    }
}
