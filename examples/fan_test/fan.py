import mraa
from time import sleep

class Fan:

  def __init__(self, port=3):
    self.port = port
    self.motor = mraa.Pwm(self.port)
    self.motor.period_ms(20)
    self.motor.pulsewidth_ms(2)
    self.motor.enable(True)

  def calibrate(self):
    ''' This is a blocking function, and should only be called once! '''
    self.motor.pulsewidth_ms(1)
    sleep(2)
    self.motor.pulsewidth_ms(1)

  def spin(self):
    self.motor.pulsewidth_us(1800)

  def set(self, speed):
    '''speed from 0 to 100'''
    power = 1000 + 10 * (speed)
    self.motor.pulsewidth_us(speed)

  def stop(self):
    self.motor.pulsewidth_ms(1)
    self.motor.enable(False)

if __name__=="__main__":
  fan = Fan()
  raw_input()
  print "Begin calibration"
  fan.calibrate()
  print "Finished calibration"
  fan.spin()
  raw_input()
  fan.stop()
