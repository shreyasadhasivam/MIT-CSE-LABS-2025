import socket
import time

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12348

s.bind((host, port))
s.listen(5)

print("\nWaiting for incoming connections..\n")

conn, addr = s.accept()

print("Recieved connection from ", addr[0], '(', addr[1],')')

s_name= conn.recv(1024)
s_name= s_name.decode()
print(s_name, "Has entered the chat room\nEnter [e] to exit\n")
name = input(str("Enter your name : "))

conn.send(name.encode())

while True:
    message= input(str("Me : "))
    if message=="e":
        message = "Left the chat room!"
        conn.send(message.encode())
        print("\n")
        break
    conn.send(message.encode())
    message= conn.recv(1024)
    message= message.decode()
    print(s_name," : ", message)
