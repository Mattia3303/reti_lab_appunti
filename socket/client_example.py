
import socket
import os
import sys

HOST = '127.0.0.1'  
PORT = [cmp] 



with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #OPTIONAL
    #Check param num
    len(sys.argv)

    #Get param
    addr = sys.argv[1]

    print("Client ready")
    #Riservare la porta per l'indirizzo HOST
    s.connect((HOST,PORT))
    print("connected")

    #Send data
    msg = [cmp]
    s.sendall(msg.encode('utf-8'))

    #Receive response
    response:str = ''
    while True:
        response += s.recv(1024).decode('utf-8')

        if '\r\n' in response:
            break


    