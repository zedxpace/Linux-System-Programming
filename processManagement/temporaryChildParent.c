#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int pId;
	int fDs;

	pId = fork();
	
	fDs = open("source.txt" ,O_RDONLY);
	if(pId == 0)	/*childProcess*/
	{
		printf("childProcess : %d\n" ,getpid());
		printf("parentProcess: %d\n" ,getppid());
		int   fd = open("source.txt" ,"write ie",678);
		ssize_t bytesWr = write(fd ,"i want to write" ,1024);	
		printf("i wrote : %d\n" ,bytesWr);
		printf("fd : %d\n" ,fd);
		close(fDs);
	}
	else		/*parentProcess*/
	{
		printf("iam parentProcess : %d\n" ,getpid());
		printf("i have fileDescriptor : %d\n" ,fDs);
		wait(NULL);
		printf("iam terminated\n");
		close(fDs);
	}
}