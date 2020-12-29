#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	unsigned int number;
	number = 0;

	int pId;
	int status;
	
	pId = fork();
	if(pId == 0)
	{
		while(number < 4294967295u)
		{
			number++;
		}
		
		printf("Child Terminated");
	}
	else 
	{
		waitpid(pId ,&status ,0);
		if(WIFEXITED(status))
		{
			printf("Parent : child Terminated normally\n");
		}
		else
		{
			printf("Parent : child terminated abnormally\n");
		}
	}
	return 0;
}