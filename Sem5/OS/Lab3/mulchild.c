// C program to demonstrate working of wait()
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid1, pid2,pid3;
	pid1 = fork();
	pid2= fork();
	pid3 = fork();
	if (pid1 == 0){
		printf("HC: hello from child 1\n");

	}
	else if (pid2 == 0){
		printf("HC: hello from child 2\n");

	}
	else if (pid3 == 0){
		printf("HC: hello from child 3\n");

	}
	else
	{
		printf("HP: hello from parent\n");
		wait(NULL);
		int a =5;
		int b=6;
		int sum =a+b;
		printf("%d\n", sum);
		printf("CT: child has terminated\n");
	}

	printf("Bye\n");
	return 0;
}
