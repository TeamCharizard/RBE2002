import mraa
import time

class State:
    def __init__(self):
        self.count = 0
        self.last_a = 0
        self.last_b = 0

c = State()

enc1A = mraa.Gpio(11)
enc1B = mraa.Gpio(8)
enc1A.dir(mraa.DIR_IN)
enc1B.dir(mraa.DIR_IN)

def isr_a(args):
    a = enc1A.read()
    if c.last_b:
        if a:
            c.count += 1
        else:
            c.count -= 1
    else:
        if a:
            c.count -= 1
        else:
            c.count += 1
    c.last_a = a


def isr_b(args):
    b = enc1B.read()
    if c.last_a:
        if b:
            c.count -= 1
        else:
            c.count += 1
    else:
        if b:
            c.count += 1
        else:
            c.count -= 1
    c.last_b = b

enc1A.isr(mraa.EDGE_BOTH, isr_a, isr_a)
enc1B.isr(mraa.EDGE_BOTH, isr_b, isr_b)

while True:
    print c.count
    time.sleep(0.5)
