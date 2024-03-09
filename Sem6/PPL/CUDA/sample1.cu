#include<stdio.h>
#include<stdlib.h>
__global__ void cuda_hello()
{
	printf("Hello world from GPU!\n");

}

int main()
{
	printf("test");
	cuda_hello<<<1,1>>>();
	return 0;
}