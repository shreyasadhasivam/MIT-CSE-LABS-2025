#include <pthread.h>
#include <stdio.h>
void* child_thread( void * param )
{
	int num = (int)param;
	int j;
	//printf("%d\n", num);
	int *arr = (int*) malloc(sizeof(num));
	arr[0]=0;
	arr[1]=1;
	//printf("%d %d ",arr[0],arr[1]);
	for(int i=2;i<num;i++)
	{
		arr[i]= arr[i-1]+arr[i-2];
	}
	// for(int i=0;i<num;i++)
 	// {
	//  	printf("%d ", arr[i]);
	// }
	
	return (void*) arr;
	//pthread_exit(0);
}
int main()
{
	pthread_t thread;
	int num;

	int *buffer;	
	printf("Enter number of Fibonacci numbers to generate: ");
	scanf("%d", &num);
	pthread_create(&thread,0,&child_thread,(void*)num);
	pthread_join( thread,(void**)&buffer );
	for(int i=0;i<num;i++)
	{
		printf("%d ", buffer[i]);
	}
	
}