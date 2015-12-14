#include "TestOdom.hpp"
#include "../charizard.hpp"
#include <MemoryFree.h>
#include <math.h>

void TestOdom::setup(){
  lidar.setup();
  base.setup();
}

void TestOdom::avoidInFront(int distance){
  if (distance < 500 && distance > 0){
    base.setSpeeds(-100,100);
  }
  else {
    base.setSpeeds(100,100);
  }
}

void TestOdom::loop(){

  bool fullSweep = lidar.read();

  if (fullSweep){
    Serial.println(freeMemory());
    base.drive();
    distances = lidar.distances;

    avoidInFront(distances[0]);

    Display.setCursor(0,0);
    Display.print("pos=");
    Display.print(base.x(),1);
    Display.print(",");
    Display.print(base.y(),1);

    Display.setCursor(0,1);
    Display.print("dir=");
    float degrees = base.dir() * 180 / 3.14159;
    Display.print(degrees ,1);


  }
}

