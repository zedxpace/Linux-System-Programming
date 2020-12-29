#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

main()
{
	int pId;
	pId = fork();
	if(pId == 0)
	{
		//execl("/bin/vi" ,"vi" ,"/xyz.txt" ,NULL);
		execl("/bin/ls" ,"-al" ,"/etc" ,NULL);
		printf("Child Process Terminating\n");
	}
	else
	{
		printf("Parent Initializing the Process\n");
	}

}