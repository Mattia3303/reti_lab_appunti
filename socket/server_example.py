#Versione in cui viene fatta la FORK ad ogni connessione

import socket
import os
import sys

HOST = '127.0.0.1'  
PORT = [cmp]         

def parse_request(socket_conn):
    request:str = ''
    while True:
        #Get first 1024 bytes and decode with standard used
        request += socket_conn.recv(1024).decode('utf-8')
        if [cmp - end of request]:
            break

    [cmp]


def serve_request(socket_conn, addr):
    print(f'Connected by {addr}') 

    [cmp] = parse_request(socket_conn)
    
    #Do something
    #Send somethin

    
    socket_conn.close()

# main
#per far partire la funzione con l'attributo socket creato grazie alla funzione
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    print("Server ready")
    #Riservare la porta per l'indirizzo HOST
    s.bind((HOST, PORT))
    print("bind completed")
    #Mettere in ascolto il server
    s.listen()
    print("server listening")

    while True:
        #Wait for an incoming connection. Return a new socket
        socket_conn, addr = s.accept()
        child_pid=os.fork()
        if child_pid==0:
            serve_request(socket_conn, addr)
            sys.exit()
        else: socket_conn.close()
