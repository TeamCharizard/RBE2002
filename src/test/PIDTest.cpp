#include "PIDTest.hpp"

PIDTest::PIDTest() :
  lPID(0.7,0,0),
  rPID(0.7,0,0){
  }

void PIDTest::setup(){
  rMotor.setup(8);
  lMotor.setup(9);
  odom.setup();

  int s = -10;
  rPID.set(s);
  lPID.set(s);

  lastUpdate = millis();
}

void PIDTest::loop(){
  long now = millis();

  if (now - lastUpdate > UPDATE_PERIOD){
    lastUpdate = now;
    odom.updateDifferential();

    int dl = odom.leftDisplacement();
    int lOut = lPID.run(dl);
    lMotor.set(lOut);

    int dr = odom.rightDisplacement();
    int rOut = rPID.run(dr);
    rMotor.set(-rOut);

    char msg[16];
    Display.setCursor(0,0);
    snprintf(msg,16,"%-3d %-3d",
        rOut,
        lOut);
    Display.print(msg);

  }
}
