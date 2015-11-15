import mraa
import time

m = mraa.Pwm(3)
m.period_ms(20)
m.pulsewidth_us(1250)
m.enable(True)

class Counter:
  count = 0

c = Counter()

# inside a python interupt you cannot use 'basic' types so you'll need to use
# objects
def test(args):
  c.count+=1
  print c.count

x = mraa.Gpio(5)
x.dir(mraa.DIR_IN)
x.isr(mraa.EDGE_BOTH, test, test)

while(1):
    pass


def SIGINTHandler(signum, frame):
    raise SystemExit

def exitHandler():
    print "Exiting"
    sys.exit(0)

atexit.register(exitHandler)
signal.signal(signal.SIGINT, SIGINTHandler)
