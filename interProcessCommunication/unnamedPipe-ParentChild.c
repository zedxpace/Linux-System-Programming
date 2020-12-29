/*Sharing process between child & parent process using pipe()*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define WRITE 1
#define READ  0

main()
{
    int fileDescriptor[2];
    int bytesRead;

    pid_t = pId;

    char readMessage[10];
    char *message = "The parent process is writing into pipes and child is reading";

    pipe(fileDescriptor);

    pId = fork();

    if(pId == 0)    /*Child Process*/
    {
        close(fileDescriptor[WRITE]);   /*CLosing write mode for child process*/
        
        bytesRead = read(fileDescriptor[READ] ,readMessage ,100);
        
        printf("Child process read ' %d ' bytes from parent process and the message if  ' %s '\n" ,bytesRead ,readMessage);

        getchar();
    }               
    else            /*parent Process*/
    {
        clode(fileDescriptor[READ]);

        write(fileDescriptor[WRITE] ,message ,strlen(message) + 1);
    }
}