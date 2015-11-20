from motor import DriveMotor
import curses
from lidar import Lidar

l = DriveMotor(6)
r = DriveMotor(5)

lidar = Lidar()

def main(stdscr):

  stdscr.nodelay(1)

  while True:

    #get c press
    c = stdscr.getch()

    if c != -1:
      #w=119 a=97 s=115 d=100
      if c == 119:
        l.set(-50)
        r.set(50)
      if c == 115:
        l.set(50)
        r.set(-50)
      if c == 100:
        l.set(-50)
        r.set(-50)
      if c == 97:
        l.set(50)
        r.set(50)
      if c == 112:
        l.set(0)
        r.set(0)
    else:
      fullSweep = lidar.read()
      if fullSweep:
        ds = lidar.getLatestDistances()
        print ds[0]
        stdscr.refresh()

if __name__ == "__main__":
  curses.wrapper(main)

