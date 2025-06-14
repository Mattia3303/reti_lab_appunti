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

//SOLO COME ESEMPIO
void parse_request(int conn_fd, uint32_t* ip_addr, uint16_t* portno) {
    struct msg message;
    bzero(&message, sizeof(message));

    if(read(conn_fd, &message, sizeof(message)) < 0) {
        error("Error in read");
    }

    *ip_addr = message.addr;
    *portno = message.port;
}

void accept_data(int conn_fd) {
    uint32_t net_ip_addr;
    uint16_t net_portno;
    parse_request(conn_fd, &net_ip_addr, &net_portno);

    printf("Addr in little endian: %u\n", ntohl(net_ip_addr));
    printf("Portno in little endian: %u\n", ntohs(net_portno));
}
///--------------------------///

int main(int argc, char *argv[])
{
    int portno = [portno];

    int sockfd;
    struct sockaddr_in server_addr;

    if (argc != 1) {
        exit(0);
    }

    //Set addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(2130706433);//127.0.0.1
    server_addr.sin_port = htons(portno);

    
    //AF_INET fisso
    //SOCK_STREAM per TCP, SOCK_DGRAM per UDP
    //_protocol è il protocollo di livello IP (0 -> IP)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        error("ERROR binding socket");
    }

    if (listen(sockfd, [cmp numero req accettate]) < 0)
        error("ERROR listening");

    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    int conn_fd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);
    
    accept_data(conn_fd);

    return 0;
}
