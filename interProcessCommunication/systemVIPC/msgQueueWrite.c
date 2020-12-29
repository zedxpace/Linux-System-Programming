#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
    int i;
    int msgQid;

    key_t key;

    char buffer[100];

    struct message
    {
        long type;
        char text[50];
    }msgWrite;

    key = ftok(argv[1] ,100);
    
    msgQid = msgget(key ,IPC_CREAT | 0664);
    printf("msgQid : %d\n" ,msgQid);

    for(i = 0 ;i < 20 ;i++)
    {
        msgWrite.type = i;
        sprintf(buffer ,"A message in queue with type %d\n" ,i);
        strcpy(msgWrite.text ,buffer);

        printf("%s\n",msgWrite.text);

        msgsnd(msgQid ,(void)&msgWrite ,sizeof(msgWrite.text) ,IPC_NOWAIT);

    }

}