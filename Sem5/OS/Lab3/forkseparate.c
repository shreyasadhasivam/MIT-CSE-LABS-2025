#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	pid = fork();

	if(pid<0)w
	{
		fprintf(stderr, "Fork Failed");
		exit(-1);

	}
	else if(pid==0)
	{
		execlp("/bin/ls", "ls", NULL);
	}
	else{
		wait(NULL);
		printf("Child complete\n");
		exit(0);
	}
}