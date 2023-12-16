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
		printf("C:hello\n");
		exit(0);
	}
	else
	{
		sleep(10);
	}
}