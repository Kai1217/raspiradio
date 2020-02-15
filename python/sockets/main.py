import socket

bdaddr = "98:5F:D3:DC:83:EB"
channel = 4
s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
s.connect((bdaddr, channel))
s_sock = server_sock.accept()
print("Accepted connection from %s" % address)
data = s_sock.recv(1024)
print("Recieved [%s]" % data)

s.listen(1)