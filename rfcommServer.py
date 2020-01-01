import bluetooth as bl

serverSocket = bl.BluetoothSocket(bl.RFCOMM)
port = 1
serverSocket.bind(("",port))
serverSocket.listen(1)

clientSocket, address = serverSocket.accept()
print("Accepted connection from ", address)

data = clientSocket.recv(1024)
print("Recieved [%s]" % data)

clientSocket.close()
serverSocket.close()