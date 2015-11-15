import mraa
from time import sleep

head = mraa.Pwm(3)
head.period_ms(20)

head.pulsewidth_ms(1)

head.enable(True)

while True:
  head.pulsewidth_us(1000)
  sleep(20)
  head.pulsewidth_us(2000)
  sleep(20)
