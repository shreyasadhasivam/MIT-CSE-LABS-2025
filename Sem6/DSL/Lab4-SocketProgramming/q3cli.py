import socket
host = '172.16.59.18'
port = 5500
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((host, port))
while True:
    msg = input("Enter a message to send : ")
    if msg.find('exit') != -1: 
        break
    s.sendall(str.encode(msg, encoding='utf-8'))
    data = s.recv(1024)
    if str(data).find('exit') != -1: 
        break
    print("The sender sent : ", str(data)) 
s.close()