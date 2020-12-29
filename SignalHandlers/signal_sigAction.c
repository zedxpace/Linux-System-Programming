#include <stdio.h>
#include <signal.h>

void sigHandler( int sigNum )
{
    printf("we are in signal handler module recieved signal %d %s\n" ,sigNum ,sys_siglist[sigNum]);
}

main()
{
    struct sigaction action = { sigHandler };

    sigaction(SIGINT ,&action ,NULL);

    while(1)
    {
    };
}