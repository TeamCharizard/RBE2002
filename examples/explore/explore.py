from motor import DriveMotor
from lidar import Lidar
import time
from time import sleep
import mraa

fan = mraa.Pwm(3)
fan.enable(True)
l = DriveMotor(6)
r = DriveMotor(5)

lidar = Lidar()

if __name__ == "__main__":
  while True:
    fullSweep = lidar.read()
    if fullSweep:
      ds = lidar.getLatestDistances()
      print ds[0]
      if ds[0] < 500:
        pass
        #stop and turn!
        l.set(10)
        r.set(10)
      else:
        pass
        l.set(-40)
        r.set(30)
