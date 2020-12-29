#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_ADDR "127.0.0.1"

void transactClient(int sock)
{
    char buf[100];
    
    int n;
    int size;

    struct sockaddr_in cliAddr; /*To revieve*/

    size  = sizeof(cliAddr);

    while(1)
    {
        bzero(buf ,sizeof(buf));

        n = recvfrom(sock ,buf ,sizeof(buf) ,0 ,(struct sockaddr *)&cliAddr ,&size);

        printf("Recieved %d bytes of data from client and echoing it\n" ,n);

        if(n < 0)
        {
            break;
        }

        size  = sizeof(cliAddr);
        n = sendto(sock ,buf ,n ,0 ,(struct sockaddr *)&cliAddr ,size);
    }

}

main(int argc ,char *argv[])
{
    struct sockaddr_in server;
    struct sockaddr_in client;

    int port;
    int sockDescriptor;
    int nld;

    port = atoi(argv[1]);
    
    sockDescriptor          = socket(AF_INET ,SOCK_DGRAM ,0);
    server.sin_family       = AF_INET;
    server.sin_addr.s_addr  = inet_addr(SERVER_ADDR);
    server.sin_port         = htons(port);

    bind(sockDescriptor ,(struct *)&server ,sizeof(server))

    transactClient(sockDescriptor);
}