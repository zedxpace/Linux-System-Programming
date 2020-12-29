#include <stdio.h>
#include <unitsd.h>
#include <fcntl.h>

main()
{
    int fileDescriptorWrite;

    char writeBuffer[100];

    mkfifo("fifo" ,0660);

    fileDescriptorWrite = open("fifo" ,O_WRONLY);

    while(1)
    {
        fgets(writeBuffer ,100 ,stdin);
        write(fileDescriptorWrite ,writeBuffer ,sizeof(writeBuffer));
    } 

    close(fileDescriptorWrite);
}