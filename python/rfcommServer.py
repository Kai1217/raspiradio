import bluetooth as bt

serverSock = bt.BluetoothSocket(bt.RFCOMM)

port = 1
serverSock.bind(("",port))
serverSock.listen(1)

clientSock,address = serverSock.accept()
print("Accepted connection from: %s" % (address))
data = clientSock.recv(1024)
print("Received [%s]" % data)
clientSock.close()
serverSock.close()
