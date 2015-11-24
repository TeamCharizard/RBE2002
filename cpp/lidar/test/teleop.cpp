#include "DriveMotor.hpp"
#include <signal.h>

DriveMotor left(6);
DriveMotor right(5);

void my_handler(int s){
  left.set(0);
  right.set(0);
  exit(1);
}


int main(int argc, char **argv){
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);

  left.set(80);
  right.set(-80);
  while (true);
}
