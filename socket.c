#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 


int main() {
    // Create a comunication point
    int file_descriptor = socket(
        protofamily: PF_INET, // IPv4,
        type: SOCK_STREAM, // TCP
            SOCK_DATAGRAM, // UDP,
        protocol: 0 // Default protocol    
    );


    //Close the socket
    close(file_descriptor);
}