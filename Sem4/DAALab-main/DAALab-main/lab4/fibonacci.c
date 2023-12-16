#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n);
int main()
{
	int n,i=0;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(int c=1;c<=n;c++)
	{
		printf("%d ", fibonacci(i));
		i++;
	}
	printf("\n");
	return 0;
}

int fibonacci(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);

}