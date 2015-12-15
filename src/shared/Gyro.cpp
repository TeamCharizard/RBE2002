#include "Gyro.hpp"

Gyro::Gyro() :
    gyro_z(0),
    gyro_zold(0),
    gerrz(0) {}

void Gyro::setup(){
  Wire.begin();

  gyro.init();
  gyro.enableDefault(); // gyro init. default 250/deg/s
  delay(1000); // allow time for gyro to settle
  for(int i =0;i<100;i++){  // takes 100 samples of the gyro
    gyro.read();
    gerrz+=gyro.g.z;
    delay(25);
  }

  gerrz = gerrz/100;
}

int Gyro::read(){
  gyro.read();

  gyro_z=(float)(gyro.g.z-gerrz)*G_gain;
  gyro_z = gyro_z*G_Dt;
  gyro_z += gyro_zold;
  gyro_zold=gyro_z;

  //to degrees!
  float angleInDegress = gyro_z * 180 / M_PI;

  if (angleInDegress > 359) angleInDegress -= 360;
  if (angleInDegress < 0) angleInDegress += 360;

  return angleInDegress;
}

