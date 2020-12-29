/*Argument to be passed as argv[1] = port on which server will work*/
#include <stdio.h>

#include <netinet/in.h>

#include <sys/socket.h>



#define SERVER_ADDRESS "127.0.0.1"  /*server Ip Address*/



void transactToClient(int sock)

{

    char buf[100];



    int N;



    while( (N = recv(sock ,buf ,sizeof(buf) ,0)) > 0 )

    {

        send(sock ,buf ,N ,0);

    }

}



main(int argc ,char *argv[])

{

    int sockFd;

    int size;

    int port;

    int csd;



    struct sockaddr_in Server;      

    struct sockaddr_in Client;



    sockFd = socket(AF_INET ,SOCK_STREAM ,0);

    port   = atoi(argv[1]);



    Server.sin_family = AF_INET;

    Server.sin_port   = htons(port);

    Server.sin_addr.s_addr   = inet_addr(SERVER_ADDRESS);

    

    bind(sockFd ,(struct sockaddr*)&Server ,sizeof(Server));



    listen(sockFd ,5);



    size = sizeof(Client);



    while(1)

    {

        csd = accept(sockFd ,(struct sockaddr*)&Client ,&size);
	printf("connection recieved");
        transactToClient(csd);

    }

}