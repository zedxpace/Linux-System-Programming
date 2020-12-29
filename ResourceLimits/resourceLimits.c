#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

main(int argc ,char *argv[])
{
    int fileDescriptor;
    int k;

    char *buf = "Hello";

    struct rlimit rLim = { 30 ,100};
    struct rlimit rlimGet;

    setrlimit(RLIMIT_FSIZE ,&rLim);  /*RLIMIT_FSIZE : setting maximum limit */

    fileDescriptor = open(argv[1] ,O_CREAT | O_TRUNC | O_RDONLY ,0600);

    getrlimit(RLIMIT_FSIZE ,&rlimGet);
    printf("Soft Link : %d\n" ,rlimGet.rlim_cur);
    printf("Hard Link : %d\n" ,rlimGet.rlim_max);

    for(k = 0 ;k <20 ;k++)
    {
        printf("Attempting to write %d by 6-bytes\n" ,strlen(buf));
        write(fileDescriptor ,buf ,strlen(buf));
        printf("successfully written %d bytes \n" ,strlen(buf));
    }

    close(fileDescriptor);
}