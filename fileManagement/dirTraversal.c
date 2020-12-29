#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	struct dirent *entry;
	char t[] = "traverseMe";
	char *name = t;
	DIR *dir;
	dir = opendir(name);	
	
	while( (entry = readdir(dir)) != NULL )
	{
		printf("[+] %s\n" ,entry->d_name);
	}

	return 0;
}