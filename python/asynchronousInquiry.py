import bluetooth as bl
import select

class Discoverer(bl.DeviceDiscoverer):
    def pre_inquiry(self):
        self.done = False

    def device_discovered(self, address, device_class, rssi, name):
        print('%s - %s' % (address, name))

    def inquiry_complete(self):
        self.done = True

d = Discoverer()
d.find_devices(lookup_names = True)

readfiles = [ d, ]

while True:
    rfds = select.select(readfiles, [], [])[0]
    if d in rfds:
        d.process_event()

    if d.done: break