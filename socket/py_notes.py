#TRASMETTERE UN MESSAGGIO 
socket_conn.sendall(msg.encode('utf-8'))

#SE VUOI CHE SERVER/CLIENT REGGA UNA CONVERSAZIONE DI PIÙ DI 2 MESSAGGI:
devi creare un ciclo while dentro la funzione chiamata dal figlio, e lo stoppi in base al protocollo  

#CREARE UNA STRINGA COME CONCATENAZIONE
resp='HTTP/1.0 404 Not Found\r\n' + \
    'Connection: close\r\n' + \
    'Content-Type: text/html\r\n' + \
    'Content-Length: %d\r\n\r\n' % len(body) + body

