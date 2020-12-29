/* inheriting signal handler by child process */
#include <stdio.h>
#include <signal.h>

void signalHandler( int sigNum )
{
    int status;
    printf("In handler ,invoked in response to signum : %d\t%s signal\n " ,sigNum ,sys_siglist[sigNum]);    /*sys_siglist : array of string which maps signal number to string names*/
    wait(&status);
}

main()
{
    pid_t pId;

    signal(SIGCHLD ,signalHandler); /* SIGCHLD is normally sent to a process to notify that one of its child processes ended, so the parent process can collect its exit code.*/

    pId = fork();
    if(pId == 0)    /*Child Process*/
    {
        printf("Child process\n");
        exit(0);
    }
    else
    {
        printf("Parent process\n");
        getchar();
    }
}