import socket
import threading


server_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_client.bind(('127.0.0.1', 1234))
server_client.listen()
clientslist = list()
users = list()
print("Server up and running ...")

def receive_message(client_socket):
    while True:
        try:
            message = client_socket.recv(1024)
            for client in clientslist:
                client.send(message)
        except:
            index = clientslist.index(client_socket)
            clientslist.remove(client_socket)
            client_socket.close()
            print(f"Bye ! {users[index]} has left the chat")
            for client in clientslist:
                client.send(f"Bye ! {users[index]} has left the chat".encode())
            users.remove(users[index])
            break


while True:
    client_socket, address = server_client.accept()
    client_socket.send("1st time".encode())
    user = client_socket.recv(1024)
    users.append(user.decode())
    clientslist.append(client_socket)
    print(f"Hola Amigos ! {user.decode()} entered the chat ...")
    for client in clientslist:
        client_socket.send(f"Hola Amigos ! {user.decode()} entered the chat ...".encode())

    thread = threading.Thread(target=receive_message, args=(client_socket,))
    thread.start()
        
    



        