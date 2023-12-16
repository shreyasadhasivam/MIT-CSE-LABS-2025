#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
void* child_thread( void * param )
{
	int n = (int)param;
	int sum;
	int *arr = (int*)calloc(n, sizeof(int));
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			continue;
		}
		else
		{
			sum += arr[i];
		}
	}
	
	return (void *)sum;
}
int main()
{
	pthread_t thread;
	
	int n,sum;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	pthread_create(&thread,0,&child_thread,(void*)n);
	//printf("thread created,");
	pthread_join( thread, (void**)&sum );
	printf("\nSum is:%d\n", sum);
	
}