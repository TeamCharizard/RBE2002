import time
import mraa

millis = lambda: int(round(time.time() * 1000))


class Lidar(object):
    '''class to represent vx-11 lidar'''

    distances = [0] * 360
    packet = [0] * 22

    startReading = False
    packetNumber = 0
    speed = 0
    packetIndex = 0
    distanceIndex = 0

    def __init__(self, port=0, baudrate=115200):
        self.port = port
        self.uart = mraa.Uart(self.port)
        self.uart.setBaudRate(baudrate)
        self.count = 0

    def read(self):
        if self.uart.dataAvailable():
            byte = self.uart.read(1)
            byte = int(ord(byte))

            if self.startReading:
                if self.packetIndex == 21:
                    self.startReading = False
                    self.processEndOfPacket()
                    # let the calling function know we're done
                    if self.distanceIndex >= 359:
                      self.count += 1
                      return True
                    return False
                else:
                    self.packet[self.packetIndex] = byte
                    self.packetIndex += 1
                    return False

            if not self.startReading and byte == 0xFA:
                self.startReading = True
                self.packetIndex = 0
                self.packet[self.packetIndex] = byte
                self.packetIndex += 1
                return False

    def processEndOfPacket(self):
        newPacketNumber = self.packet[1]

        if (newPacketNumber - self.packetNumber) == 1:
            for i in range(22):
                if i == 2:
                    self.speed = self.packet[3] << 8 | self.packet[2]
                    self.speed /= 64
                elif self.isDataIndex(i):
                    self.distanceIndex = (newPacketNumber - 0xA0) * 4 + i/4 - 1
                    if self.distanceIndex >= 0 and self.distanceIndex < 360:
                        if (self.packet[i+1] & 0x80) >> 7:
                            self.distances[self.distanceIndex] = 0
                        else:
                            d = self.packet[i] | ((self.packet[i+1] & 0x3F) << 8)

                            # cap between limits
                            if d < 0 or d > 6000:
                                d = 0

                            # finally, store valid data
                            self.distances[self.distanceIndex] = d

                else:
                    #checksum, packet num, and start bit go here
                    pass


        self.packetNumber = newPacketNumber
        if self.packetNumber >= 0xF9:
            self.packetNumber = 0x9F

    def isDataIndex(self, index):
        return index == 4 or index == 8 or index == 12 or index == 16

    def getLatestDistances(self):
        return self.distances

