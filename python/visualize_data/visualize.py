from lidar import Lidar
from math import pi,sin,cos
import re
import Tkinter

def dtr(x):
  return (2*pi*x)/360

def convert_to_points(canvas, s, a, b, scale = 1, polar=True):
  i=0
  points = []
  while i<len(a):
    x = -1
    y = -1
    if polar:
      x = cos(a[i]) * b[i]
      y = sin(a[i]) * b[i]
    else:
      x=a[i]
      y=b[i]
    x*=scale
    y*=scale
    p = 3 #size of dots
    canvas.create_rectangle(s/2+x,s/2-y,s/2+x+p,s/2-y+p)
    i += 1

if __name__ == "__main__":
    lidar = Lidar()

    s = 800
    m_scale = 0.25
    distances = [0] * 360
    t = [dtr(e) for e in range(360)]

    window = Tkinter.Tk()
    canvas = Tkinter.Canvas(window,width=s,height=s)

    while True:
        readDistances = lidar.read()
        if readDistances:
            distances = lidar.getLatestDistance()
            canvas.delete('all')
            convert_to_points(canvas, s, t, distances, scale = m_scale)
            canvas.pack()
            window.update()

