// C program to demonstrate working of wait()
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid== 0){
		printf("HC: hello from child\n");
		for(int i=0;i<5;i++)
		{
			printf("hello %d\n", i);
		}
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
