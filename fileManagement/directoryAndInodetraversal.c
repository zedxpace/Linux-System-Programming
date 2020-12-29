#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
void search(int i_nodeNumber ,char t[])
{
	struct dirent *entry;
        char *name = t;
        DIR *dir;
        dir = opendir(name);
        DIR *iu;
        while( (entry = readdir(dir)) != NULL )
        {
                if(!(strcmp(entry->d_name ,".")) | !(strcmp(entry->d_name ,"..")))
                {
                        printf("");
                }     
                else 
                {
               		if(i_nodeNumber == entry->d_ino)
			{
				printf("[+] %s\n" ,entry->d_name);
			}
               		iu = opendir(entry->d_name);
                	if(  iu )
                	{
				search(0,entry->d_name);
                	}
               }
	}
}
void traverse(char t[])
{
	struct dirent *entry;
 	char *name = t;
        DIR *dir;
        dir = opendir(name);
	DIR *iu;
        while( (entry = readdir(dir)) != NULL )
        {
		if(!(strcmp(entry->d_name ,".")) | !(strcmp(entry->d_name ,"..")))
		{
			printf("");
		}
		else
		{
                printf("\t[+] %s\n" ,entry->d_name);

		iu = opendir(entry->d_name);
        		if(  iu )
                	{
                        	traverse(entry->d_name);
                	}
		}

        }

}

int main(int argc ,char *argv[])
{
	struct dirent *entry;
	char t[] = "traverseMe";
	char *name = t;
	
	char *arg = argv[1];
	int isF = strcmp(arg ,"-f");

int isC = strcmp(arg ,"-c");
	if(isF == 0)
	{
	traverse(name);
	}
	printf("=====\n");
	if(isC == 0)
	{
	search(76565,name);
	}

	return 0;
}