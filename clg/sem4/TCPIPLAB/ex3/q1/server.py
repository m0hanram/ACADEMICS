import socket


s = socket.socket(family=socket.AF_INET,  type=socket.SOCK_DGRAM)
s.bind(('127.0.0.1',1234))
print('The server is up and listening...')
while True:
    client = s.recvfrom(1024)
    s.sendto(str.encode("message recieved"), client[1])
