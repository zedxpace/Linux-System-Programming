#include <stdio.h>
#include <signal.h>

void signalHandler( int sigNum )
{
    switch(sigNum)
    {
        case SIGTERM :
            printf("SIGTERM SIGNAL RECIEVED\N");
            break;
        case SIGINT :
            printf("SIGINT SIGNAL RECIEVED\N");
            break;
        case SIGCONT :
            printf("SIGCONT SIGNAL RECIEVED\N");
            break; 
    }
}

main()
{
    char buffer[100] = "\0";

    sigset_t block;

    signal(SIGTERM ,signalHandler);
    signal(SIGINT  ,signalHandler);
    signal(SIGCONT ,signalHandler);

    sigemptyset(&block);                    /*refering to empty sigset_t variable so it doesnt refer to any signals*/
    sigaddset(&block ,SIGTERM);             /*Adding signals to empty set*/
    sigaddset(&block ,SIGINT);

    sigprocmask(SIG_BLOCK ,&block ,NULL);   /*Blocking signal & providing list of Signals to be blocked as block*/

    while(strcmp(buffer ,"n") != 0)
    {
        printf("Enter a string : ");
        gets(buffer);
        puts(buffer);
    }

    sigprocmask(SIG_UNBLOCK ,&block ,NULL); /*UnBlocking signal*/

    while(1)
    {
        printf("Program Running\n");
    }

    return 0;

}