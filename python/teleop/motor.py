import mraa

class DriveMotor:

 def __init__(self, port):
   self.pwm = mraa.Pwm(port)
   self.pwm.period_ms(20)
   self.pwm.pulsewidth_us(1400)
   self.pwm.enable(True)

 def set(self, speed):
   #pulsewidth = 0.0
   #if speed < -5:
     #pulsewidth = 0.0013*speed**3+0.1439*speed**2 + 6.196*speed+1491.1
   #elif speed > 5:
     #pulsewidth = 0.001*speed**3 - 0.1029*speed**2+4.6876*speed + 1527.9
   #else:
     #pulsewidth = 1500
   pulsewidth = (speed + 100) * 5 + 900
   self.pwm.pulsewidth_us(int(pulsewidth))
