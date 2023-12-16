#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	//int status;
	pid_t pid;
	pid = fork();

	if(pid<0)
	{
		fprintf(stderr, "Fork Failed");
		exit(-1);

	}
	else if(pid==0)
	{

		execlp("./q1","q1", NULL);
		printf("I have finished\n");
		exit(0);
	}
	else{
		wait(NULL);
		printf("Child complete\n");
		exit(0);
	}
}