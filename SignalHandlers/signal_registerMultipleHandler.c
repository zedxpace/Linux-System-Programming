/* Common method for multiple signal handling */
#include <stdio.h>
#include <signal.h>

/* execution of code can be aborted in signal handler itself by using the exit(0) beyond the  */
void handleSignal( int sigNo )
{
	printf("In signal handler module recieved signal is %d %s\n" ,sigNo ,sys_siglist[sigNo]);
}

main( void )
{
	signal(SIGINT  ,handleSignal);	/* SIGINT : interrupt from keyboard CTRL+C */
	signal(SIGTERM ,handlerSignal);	/* SIGTERM: termination signal *

	getchar();
}