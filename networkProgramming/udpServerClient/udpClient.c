#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

void transactServer(int sock ,char *servIp ,int port)
{
    char buf[100];
    
    int n;
    int size;

    struct sockaddr_in server;

    memset((char *)&server ,0 ,sizeof(server));
    
    server.sin_family       = AF_INET;

    server.sin_port         = htons(port);

    inet_aton(servIp ,&server.sin_addr);

    size = sizeof(server);

    while(1)
    {
        bzero(buf ,sizeof(buf));

        fgets(buf ,sizeof(buf)-1 ,stdin);

        n = strlen(buf);

        buf[n] = 0;
        printf("printing buffer %s\n" ,buf);

        size = sizeof(server);

        n = sendto(sock ,buf ,n ,0 ,(struct sockaddr *)&server ,size);

        size = sizeof(server);

        n = recvfrom(sock ,buf ,sizeof(buf) ,0 ,(struct sockaddr *)&server ,&size);

        // printf("Recieved %d bytes of data from client and echoing it\n" ,n);

        if(n < 0)
        {
            break;
        }
        else 
        {
            write(1 ,buf ,n);
        }
    }

}

main(int argc ,char *argv[])
{
    int sockDescriptor;
    int port;

    struct sockaddr_in server;

    sockDescriptor = socket(AF_INET ,SOCK_DGRAM ,0);

    port = atoi(argv[2]);

    transactServer(sockDescriptor ,argv[1] ,port);
}