import mraa
import math
from time import sleep

head = mraa.Pwm(3)
head.period_ms(20)
head.pulsewidth_ms(1)
head.enable(True)

sensor = mraa.Aio(0)

distance = 310 # distance to candle in mm
myHeight = 190 # distance to neck pivot in mm

while True:
  #send to top and measure!
  minVal = 1024
  minPulse = 2000
  head.pulsewidth_us(500)
  sleep(.2)
  for i in range(500,2300,10):
    head.pulsewidth_us(i)
    total = 0

    s = 10
    for e in range(s):
      total += sensor.read()

    intensity = total/s

    if intensity < minVal:
      minVal = intensity
      minPulse = i

    sleep(.01)

  head.pulsewidth_us(minPulse)
  angle = ((minPulse - 500)* 65) / 1800 + -30
  height = myHeight + math.tan(angle*math.pi/180.0)*distance
  print angle,height

  raw_input()
