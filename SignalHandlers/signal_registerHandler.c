/* Registering handler with the kernel */
#include <stdio.h>
#include <signal.h>

void sigHandler(int sigNo)
{
	printf("In signal handler module recieved signal is %d %s\n" ,sigNo ,sys_siglist[sigNo]);
}

main(void)
{
	signal(SIGINT ,sigHanlder);
	
	getchar();
}