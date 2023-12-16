#include <pthread.h>
#include <stdio.h>
void* child_thread( void * param )
{
	int a = (int)param;
	printf("\n%d\n", a);
	int sum = a+5;
	return (void *)sum;
}
int main()
{
	pthread_t thread;
	int sum;
	int a;
	printf("Enter a: ");
	scanf("%d", &a);
	pthread_create(&thread,0,&child_thread,(void*)a);
	pthread_join( thread, (void**)&sum );
	printf("\nSum is:%d\n", sum);
	
}