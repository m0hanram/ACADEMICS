import socket
import subprocess


HEADER = 10
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1',5000))
s.listen()
client_socket, address = s.accept()
print('the address is', address)
while True:
    data = client_socket.recv(16)
    if len(data)<=0:
        break;
    if data.decode().upper() == 'R':
        command = subprocess.Popen(['netstat','-r'], stdout=subprocess.PIPE)
        output, error = command.communicate()
        output = (f'{len(output.decode()):<{HEADER}}'+output.decode()).encode()
        print(output)
    elif data.decode().upper() == 'S':
        command = subprocess.Popen(['netstat','-s'], stdout=subprocess.PIPE)
        output, error = command.communicate()
        output = (f'{len(output.decode()):<{HEADER}}'+output.decode()).encode()
        print(output)
    elif data.decode().upper() == 'A':
        command = subprocess.Popen(['arp','-a'], stdout=subprocess.PIPE)
        output, error = command.communicate()
        output = (f'{len(output.decode()):<{HEADER}}'+output.decode()).encode()
        print(output)
    client_socket.sendall(output)
    s.close()