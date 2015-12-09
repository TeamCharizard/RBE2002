#include "TestOdom.hpp"
#include "../main.hpp"
#include <MemoryFree.h>
#include <math.h>

void TestOdom::setup(){
  lidar.setup();
  base.setup();
}

void TestOdom::avoidInFront(int distance){
  if (distance < 500 && distance > 0){
    base.setSpeeds(-10,10);
  }
  else {
    base.setSpeeds(10,10);
  }
}

void TestOdom::loop(){

  bool fullSweep = lidar.read();

  if (fullSweep){
    Serial.println(freeMemory());
    base.run();
    distances = lidar.distances;

    avoidInFront(distances[0]);

    char msg1[16];
    char msg2[16];
    snprintf(msg1,16,"pos = (%d, %d)\n", (int)base.x(), (int)base.y());
    snprintf(msg2,16,"dir = %d\n", (int)base.dir());
    Display.setCursor(0,0);
    Display.print(msg1);
    Display.setCursor(0,1);
    Display.print(msg2);

  }
}

