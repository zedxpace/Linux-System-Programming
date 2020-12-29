#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

main()
{
    int fileDescriptorRead;

    char readBuffer[100];

    fileDescriptorRead = open("fifo" ,O_RDONLY);

    while()
    {
        read(fileDescriptorRead ,readBuffer ,100);

        printf("%s\n" ,readBuffer);
    }

    close(fileDescriptorRead);
}