#include "FireFinder.hpp"
#include "Lidar.hpp"
#include <iostream>

FireFinder ff;

int main(int argc, char** argv){
  while (true){
    ff.checkHeightInFront(30);
    getchar();
  }
}
