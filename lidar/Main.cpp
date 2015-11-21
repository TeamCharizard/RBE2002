#include "Lidar.hpp"
#include "DriveMotor.hpp"

int main(int argc, char **argv){
  Lidar lidar;
  while (true) {
    lidar.read();
  }
}
