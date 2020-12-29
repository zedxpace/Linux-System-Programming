/* signal from one process to other : kil() */
#include <stdio.h>
#include <signal.h>

main()
{
	pid_t pId;
	int status;
	
	pId = fork();
	if( pId == 0 )
	{
		printf("child Process Activated : %d\n" ,getpid());
	}
	else
	{
		printf("Parent Process Activated : %d\n" ,getpid());
		kill(pId ,SIGKILL);
		wait(&status);
		printf("child Process is Killed\n");
		printf("Parent Terminated\n");
		
		getchar();
	} 
			
}