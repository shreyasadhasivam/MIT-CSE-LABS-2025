#include<pthread.h>
#include<stdio.h>
pthread_mutex_t mutex;
volatile int counter1 = 0;
volatile int counter2 = 0;
void * count(void* param){
	for(int i=0;i<100;i++)
	{
		pthread_mutex_lock(&mutex);
		counter1++;
		printf("Count1=%i\n", counter1);
		pthread_mutex_unlock(&mutex);
		counter2++;
		printf("Count2=%i\n", counter2);
	}
}

int main()
{
	pthread_t thread1, thread2;
	pthread_mutex_init(&mutex,0);
	pthread_create(&thread1,0,count,0);
	//counter =0;
	pthread_create(&thread2,0,count,0);
	pthread_join(thread1,0);
	//counter =0;
	pthread_join(thread2,0);
	pthread_mutex_destroy(&mutex);
	return 0;
}