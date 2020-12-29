#include <stdio.h>
#include <sys/ipc.h>

main()
{
    key_t keyOne;
    key_t keyTwo;
    key_t keyThree;

    keyOne  = ftok(argv[1] ,100);
    keyTwo  = ftok(argv[2] ,100);
    keyThree= ftok(argv[3] ,100);

    printf("keyOne : %d\nkeyTwo : %d\nkeyThree : %d\n" ,keyOne ,keyTwo ,keyThree);
}