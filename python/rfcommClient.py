import bluetooth as bl

bdAddress = "B8:27:EB:85:59:E3"
port = 1
socket = bl.BluetoothSocket(bl.RFCOMM)
socket.connect((bdAddress, port))
socket.send("Hello!")
socket.close()