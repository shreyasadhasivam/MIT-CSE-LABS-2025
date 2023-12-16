#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

//stat returns information about the file denoted by the path
//fstat returns info about the file represented by the file descriptor fd
//lstat is identical to stat except that in the case of a symbolic link, 
//lstat returns info about the link itself and not the target file.

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret;
	//char *oldpath,*newpath;
	if(argc<2)
	{
		fprintf(stderr,"usage:%s<file>\n",argv[0]);
		return 1;
	}
	// printf("Enter the old path: ");
	// scanf("%s", argv[1]);
	// printf("Enter the new path: ");
	// scanf("%s", argv[2]);
	ret = link(argv[1],argv[2]);
	
	if(ret)
		perror("link");
	
	printf("\nBefore linking:\n");
	system("ls");
	
	int ret2 = unlink(argv[2]);

	if(ret2)
		perror("link");
	printf("\nAfter unlinking: \n");
	system("ls\n");

	return 0;
}