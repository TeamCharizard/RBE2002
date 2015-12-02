import mraa
from time import sleep

head = mraa.Pwm(9)
head.period_ms(20)

head.pulsewidth_ms(1)

head.enable(True)

while True:
  head.pulsewidth_us(540)
  sleep(1)
  head.pulsewidth_us(2300)
  sleep(1)
