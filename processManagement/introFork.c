#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Before Fork\n");
	fork();
	printf("After Fork\n");
	
	return 0;
}