#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include <time.h>

//stat returns information about the file denoted by the path
//fstat returns info about the file represented by the file descriptor fd
//lstat is identical to stat except that in the case of a symbolic link, 
//lstat returns info about the link itself and not the target file.

int main(int argc, char *argv[])
{
	struct stat sb;
	struct tm dt;
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
	printf("Device node: %ld\n" , sb.st_dev);
	printf("Inode is %ld\n", sb.st_ino);
	printf("File size: %ld\n", sb.st_size);
	printf("Number of hard links: %ld\n", sb.st_nlink);
	printf("File access: ");
    if (sb.st_mode & R_OK)
        printf("read ");
    if (sb.st_mode & W_OK)
        printf("write ");
    if (sb.st_mode & X_OK)
        printf("execute");
    printf("\nUser ID of owner: %d\n", sb.st_uid);
    printf("Group ID of owner: %d\n", sb.st_gid);
    printf("Device ID of file: %ld\n", sb.st_rdev);
    printf("Blocksize of file:%ld\n", sb.st_blksize);
    printf("Number of blocks allocated: %ld", sb.st_blocks);
    dt = *(gmtime(&sb.st_atime));
    printf("\nAccessed on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
    dt = *(gmtime(&sb.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

	
	 dt = *(gmtime(&sb.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
    printf("\nFile type: ");
	switch(sb.st_mode & S_IFMT)
	{
		case S_IFBLK:
			printf("Block device mode\n");
			break;
		case S_IFCHR:
			printf("Character device node\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("FIFO\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown\n");
			break;
	}
	return 0;
}