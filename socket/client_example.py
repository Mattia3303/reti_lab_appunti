
import socket
import os
import sys

HOST = '127.0.0.1'  
PORT = 1025 



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


    