import socket


HEADER = 10
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
str = input("Enter the option R-routing table S-number of connections A-arp cache")
s.connect(('127.0.0.1',5000))
s.sendall(str.encode())
data = s.recv(16)
msgsize = int(data.decode()[:HEADER])
data = s.recv(msgsize)
print(data.decode()[HEADER:])
