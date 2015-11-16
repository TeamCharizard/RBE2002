from lidar import Lidar
from time import sleep
import mraa
import time

millis = lambda: int(round(time.time() * 1000))

lidar = Lidar()

if __name__ == "__main__":
  t0 = millis()
  while True:
    # get the wall distances
    fullSweep = lidar.read()
    if fullSweep:
      d = lidar.getLatestDistances()
      print d[0]

