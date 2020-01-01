import bluetooth

targetName = "OPPO R11s"
targetAddress = None

nearbyDevices = bluetooth.discover_devices()

for bdaddr in nearbyDevices:
    if targetName == bluetooth.lookup_name(bdaddr):
        targetAddress = bdaddr
        break

if targetAddress is not None:
    print("Found target bluetooth device with address ", targetAddress)
else:
    print("Could not find target bluetooth device nearby")    