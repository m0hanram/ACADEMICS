import socket
import threading


client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1', 1234))
user = input("Enter your name : ")


def receive_message():
    while True:
        try:
            data = client_socket.recv(1024)
            if data.decode() == '1st time':
                client_socket.send(user.encode())
            else:
                print(data.decode())
        except:
            print("Connection lost ...")
            client_socket.close()
            break



def send_message():
    while True:
        data = user + ':' + input("")
        client_socket.send(data.encode())


receive_message_thread = threading.Thread(target=receive_message)
receive_message_thread.start()
send_message_thread = threading.Thread(target=send_message)
send_message_thread.start()
