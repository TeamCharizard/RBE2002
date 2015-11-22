import mraa

m = mraa.Pwm(3)
m.period_ms(20)
min_pw=1000
max_pw=2000

m.pulsewidth_us(min_pw)

m.enable(True)

while True:
  pass
