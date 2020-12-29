/* sending signal to itself : raise() */

#include <stdio.h>
#include <signal.h>
	
main()
{
	printf("we are in process with pId : %d\n" ,getpid());
	/*kill(getpid() ,SIGILL)*/
	
	getchar();	
	raise(SIGKILL);
}