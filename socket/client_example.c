#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 



void error(char *msg)
{
    perror(msg);
    exit(0);
}




int main(int argc, char *argv[])
{
    char *hostname = "localhost";
    int server_portno = [cmp];

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    //AF_INET fisso
    //SOCK_STREAM per TCP, SOCK_DGRAM per UDP
    //_protocol è il protocollo di livello IP (0 -> IP)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(server_portno);

    if (connect(sockfd, (const struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    

    //Sent data

    return 0;
}
