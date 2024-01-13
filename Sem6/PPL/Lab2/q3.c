#include"mpi.h"
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
	int rank, size,n;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;

	//int bufsize = n*sizeof(int);
	//char *buf = malloc(bufsize);
	// x = 5;
	//printf("Test");
	int sq,cube,i;
	int arr[n];
	//printf("%d", argc);
	if(rank == 0)
	{
		printf("Enter the size of array:\n");
		scanf("%d", &n);
		int bufsize = n*sizeof(int);
		char *buf = malloc(bufsize);
		printf("Enter elements:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d", &arr[i]);
		}
		
		MPI_Buffer_attach(buf, bufsize+ MPI_BSEND_OVERHEAD);
		for(i=0;i<n;i++)
		{
			MPI_Bsend(&arr[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
		}
		free(buf);
		MPI_Buffer_detach(&buf,&bufsize);

	}
	else if(rank%2==0)
	{
		//printf("IN rank 1\n");
		MPI_Recv(&arr[i],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process %d\n", arr[i], rank);
		sq = arr[i]*arr[i];
		printf("Square of received element: %d\n", sq);
		//fflush(stdout);
	}
	else if(rank%2!=0)
	{
		//printf("IN rank 1\n");
		MPI_Recv(&arr[i],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process %d\n", arr[i], rank);
		cube = arr[i]*arr[i]*arr[i];
		printf("Cube of received element: %d\n", cube);
	}
	
	MPI_Finalize();
	return 0;
}