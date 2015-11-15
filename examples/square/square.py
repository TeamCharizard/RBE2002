import mraa
from time import sleep

leftMotor = mraa.Pwm(5)
rightMotor = mraa.Pwm(6)

leftMotor.period_ms(20)
rightMotor.period_ms(20)

leftMotor.pulsewidth_ms(1)
rightMotor.pulsewidth_ms(2)

leftMotor.enable(True)
rightMotor.enable(True)


def turnLeft():
  leftMotor.pulsewidth_ms(2)
  rightMotor.pulsewidth_ms(2)
  sleep(1)

while True:
  leftMotor.pulsewidth_ms(1)
  rightMotor.pulsewidth_ms(2)
  sleep(2)
  turnLeft()
