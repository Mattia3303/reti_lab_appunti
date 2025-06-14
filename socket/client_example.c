#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 


struct msg
{
    uint32_t addr;
    char middle_blank;
    uint16_t port;
    char end_blank;
};

void error(char *msg)
{
    perror(msg);
    exit(0);
}


void send_data(int sockfd, char* addr_dotted_dec, char* portno_str){
    //Non so fare la conversione ora quindi metto già i valori
    struct msg message;

    uint32_t addr = htonl(2147483648);
    uint16_t port = htons(32768);
    char blank = '\0';

    printf("chechpoint 1\n");
    bcopy(&addr, &message.addr, sizeof(addr));
    bcopy(&blank, &message.middle_blank, sizeof(blank));
    bcopy(&port, &message.port, sizeof(port));
    bcopy(&blank, &message.end_blank, sizeof(blank));

    printf("chechpoint 2\n");

    // Debug byte a byte
    unsigned char* p = (unsigned char*)&message;
    for (int i = 0; i < sizeof(message); i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");

    int n = write(sockfd, &message, sizeof(message));
    if (n < 0) 
         error("ERROR writing to socket");
    printf("chechpoint final\n");
}


int main(int argc, char *argv[])
{
    char *hostname = "localhost";
    int server_portno = 1025;

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    //Parametri da linea di comando
    char *addr;
    char *portno;

    if (argc != 3) {
        exit(0);
    }
    
    addr = argv[1];
    portno = argv[2];
    
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
    
    printf("chechpoint 3\n");

    send_data(sockfd, addr, portno);

    return 0;
}
