#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
		perror("Child not created\n");
	else if(pid == 0)
	{
		printf("C:The process ID: %d\n", getpid());
		printf("C:The process ID of the parent is: %d\n", getppid());
	}
	else
	{
		printf("P:The process ID is: %d\n", getpid());
		printf("P: The Process ID of my parent is:%d\n", getppid());
		printf("P: The process ID of my child is:%d\n", pid);	
	}
}