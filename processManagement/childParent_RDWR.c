#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(int argc ,char *argv[])

{

	int pId;
	int fileDescriptor;

	ssize_t bytesRead;
	ssize_t bytesWritten;

	char buf[BUFSIZ];
	
	
	fileDescriptor = open("source.txt" ,O_RDWR);

	pId = fork();
	if(pId == 0)	/*Child Process*/
	{
		printf("Child process activated\n");
		char *param = argv[1];
	        bytesWritten = write(fileDescriptor ,param ,strlen(param));
                printf("Total Bytes Written : %d\n" ,bytesWritten);
		getchar();		
		close(fileDescriptor);
		printf("Child Terminated\n");
	}
	else		/*Parent Process*/
	{
		printf("parent process activated\n");
		while(1)

                {
                        bytesRead = read(fileDescriptor,buf ,512);

			if(bytesRead > 0)
                        {
                                printf("\n%s\n" ,buf);
                                printf("Totals Bytes Read : %d\n" ,bytesRead);
                        }
                        else
                        {
                                break;
                        }
                }	

		wait(NULL);
		close(fileDescriptor);	
		printf("Parent Terminated\n");		

	}
	close(fileDescriptor);
	return 0;
}