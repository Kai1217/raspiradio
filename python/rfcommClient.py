import bluetooth as bl

print("Searching for devices")
nearbyDevices = bl.discover_devices(lookup_names=True)
print("Found %d devices" % len(nearbyDevices))

for name, addr in nearbyDevices:
    print("%s - %s" % (addr, name))
