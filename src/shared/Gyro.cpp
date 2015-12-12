#include "Gyro.hpp"

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

float Gyro::read(){
    gyro.read();

    gyro_z=(float)(gyro.g.z-gerrz)*G_gain;
    gyro_z = gyro_z*G_Dt;
    gyro_z += gyro_zold;
    gyro_zold=gyro_z;

    return gyro_z;
}

