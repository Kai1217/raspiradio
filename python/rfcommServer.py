import bluetooth as bl

serverSocket = bl.BluetoothSocket(bl.RFCOMM)
port = 4
serverSocket.bind(("",port))
serverSocket.listen(4)

clientSocket, address = serverSocket.accept()
print("Accepted connection from ", address)
while True:
    data = clientSocket.recv(1024)
    if not data: break
    clientSocket.send(data)

#def recvall(clientSocket):
#    BUFFERSIZE = 4096
 #   data = b''
  #  while True:
   #     part = clientSocket.recv(BUFFERSIZE)
    #    data += part
     #   if len(part) < BUFFERSIZE:
      #      break
    #return data
#data = recvall(clientSocket)
#while True:
#   print("Recieved [%s]" % data)

clientSocket.close()
serverSocket.close()