/*Args to be passed argv[1] = ip of server
                    argv[2] = port of server*/
#include <stdio.h>

#include <unistd.h>

#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>



#define SERVER_ADDR "127.0.0.1"



void transactServer(int sock)

{

    char buf[100];



    int n;



    while(1)

    {

        bzero(buf ,sizeof(buf));



        fgets(buf ,sizeof(buf)-1 ,stdin);



        send(sock ,buf ,strlen(buf) ,0);
	printf("msg Sent to \n");
	n = recv(sock ,buf ,sizeof(buf) ,0);

        write(STDOUT_FILENO ,buf ,n);

    }

}



main( int argc ,char *argv[] )

{

    int sockFd;

    int port;



    struct sockaddr_in server;



    sockFd = socket(AF_INET ,SOCK_STREAM ,0);

    port   = atoi(argv[2]);



    server.sin_family = AF_INET;

    server.sin_port   = htons(port);

    server.sin_addr.s_addr = inet_addr(argv[1]);



    connect(sockFd ,(struct sockaddr *)&server ,sizeof(server));

    transactServer(sockFd);

}