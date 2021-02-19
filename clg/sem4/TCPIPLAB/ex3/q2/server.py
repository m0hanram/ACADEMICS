import socket


s = socket.socket(family=socket.AF_INET,  type=socket.SOCK_DGRAM)
s.bind(('127.0.0.1',1234))
print('The server is up and listening...')
while True:
    client = s.recvfrom(1024)
    s.sendto(client[0], client[1])
    print(f"the client msg : {client[0]}")
    print(f"the client address: {client[1]}")
