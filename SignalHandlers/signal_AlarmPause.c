#include <stdio.h>
#include <signal.h>

void signalHandler( int sigNum )
{
    printf("we are in signal handler module recieved signal %d %s\n" ,sigNum ,sys_siglist[sigNum]);
}

main()
{
    int ret;
    signal(SIGALRM ,signalHandler);

    printf("About to call Alarm\n");

    ret = alarm(10);

    printf("alarm() system call returns %d\n" ,ret);

    ret = alarm(20);

    printf("alarm() system call returns %d\n" ,ret);
    printf("pause will block\n");

    pause();

    printf("SIGALARM is rasied and handled ,the flow continues\n");
    

}