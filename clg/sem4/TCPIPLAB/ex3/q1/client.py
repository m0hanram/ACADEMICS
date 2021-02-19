import socket


s = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
s.sendto(str.encode("HI SERVER THIS IS CLIENT !"), ('127.0.0.1',1234))
servermsg = s.recvfrom(1024)
print(f"Message from server : {servermsg[0]}")