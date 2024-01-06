#include"mpi.h"
#include<stdio.h>

int main(int argc, char* argv[])
{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	float a= 5;
	float b=10;
	float res;
	if(rank == 0)
	{
		res = a+b;
		printf("P%d: %.2f+%.2f=%.2f\n", rank,a,b,res);
	}
	else if(rank == 1)
	{
		if(a>b){
			res = a-b;
			printf("P%d: %.2f-%.2f=%.2f\n", rank,a,b,res);
		}
		res = b-a;
		printf("P%d: %.2f-%.2f=%.2f\n", rank,b,a,res);
		
	}
	else if(rank == 2)
	{
		res = a/b;
		printf("P%d: %.2f/%.2f=%.2f\n", rank,a,b,res);
	}
	else if(rank == 3)
	{
		res = a*b;
		printf("P%d: %.2f*%.2f=%.2f\n", rank,a,b,res);
	}

}