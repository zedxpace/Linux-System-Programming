/*Child process is reading while its sibling is writing using pipe()*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define READ 0 
#define WRITE 1

main()
{
    int fileDescriptor[2];
    int bytesRead;

    char readMessage[100];
    char *message = "Child process writes and its sibling reads";

    pid_t pIdOne;
    pid_t pIdTwo;

    pipe(fileDescriptor);

    pIdOne = fork();
    if(pIdOne == 0)     /*Child Process*/
    {
        close(fileDescriptor[WRITE]);

        bytesRead = read(fileDescriptor[READ] ,readMessage ,100)
        printf("child process read ' %d ' bytes written by its sibling and the message is ' %s '\n" ,bytesRead ,readMessage);

        getchar();
    }
    else                /*Parent process*/
    {
        pIdTwo = fork();
        if(pIdTwo == 0) /*Sibling process*/
        {
            close(fileDescriptor[READ]);

            write(fileDescriptor[WRITE] ,message ,strlen(message)+1);
        }
    }

} 