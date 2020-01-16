import socket

bdaddr = "B8:27:EB:85:59:E3"
channel = 4
s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
s.connect((bdaddr, channel))
s_sock = server_sock.accept()
print("Accepted connection from %s" % address)
data = s_sock.recv(1024)
print("Recieved [%s]" % data)

s.listen(1)