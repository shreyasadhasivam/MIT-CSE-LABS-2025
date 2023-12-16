#include <pthread.h>
#include <stdio.h>
int num;
void* child_thread1( void * param )
{
	int *arr = (int*)param;
	int evensum;
	for(int i=0;i<num;i++)
	{
		if(arr[i]%2==0)
		{
			evensum+=arr[i];
		}
	}
	printf("Even sum is : %d\n", evensum);
	return 0;
}
void* child_thread2( void * param )
{
	int *arr = (int*)param;
	int oddsum;
	for(int i=0;i<num;i++)
	{
		if(arr[i]%2!=0)
		{
			oddsum+=arr[i];
		}
	}
	printf("Odd sum is : %d\n", oddsum);
	
	return 0;
}
int main()
{
	pthread_t thread1;
	pthread_t thread2;
	int oddsum,evensum;
	
	printf("Enter size of array: ");
	scanf("%d", &num);
	int arr[num];
	printf("Enter elements of the array: ");
	for(int i=0;i<num;i++)
	{
		scanf("%d", &arr[i]);
	}
	
	pthread_create(&thread1,0,&child_thread1,(void*)arr);
	//printf("thread 1");
	pthread_create(&thread2,0,&child_thread2,(void*)arr);
	//printf("thread 2");
	pthread_join( thread1,0);
	pthread_join( thread2,0);
	//printf("Sum of Even numbers: %d\n", evensum);
	//printf("Sum of odd numbers: %d\n", oddsum);
	
	
}