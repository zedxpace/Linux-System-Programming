#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pId;
	pId = fork();
	if(pId == 0)
	{
		printf("Child Process with pId : %d\n" ,getpid());
	}
	else
	{
		printf("Parent Process with pId : %d\n" ,getpid());
	}
	
	return 0;
}