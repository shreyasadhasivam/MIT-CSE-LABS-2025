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
	if(argc<2)
	{
		fprintf(stderr,"usage:%s<file>\n",argv[0]);
		return 1;
	}
	ret = stat(argv[1],&sb);
	if(ret)
	{
		perror("stat");
		return 1;
	}
	printf("%s inode is %ld\n", argv[1], sb.st_ino);
	return 0;
}