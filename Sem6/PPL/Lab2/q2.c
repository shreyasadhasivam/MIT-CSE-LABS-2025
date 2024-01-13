#include"mpi.h"
#include<stdio.h>

int main(int argc, char * argv[])
{
	int rank, size, x;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	// x = 5;
	//printf("Test");
	if(rank == 0)
	{
		printf("Enter number:");
		scanf("%d", &x);
		//printf("In rank 0:\n");
		for(int i=0;i<4;i++)
		{
			MPI_Send(&x,1,MPI_INT,i,1,MPI_COMM_WORLD);
			fprintf(stdout, "I have sent %d from process 0\n", x);
		}
		
		fflush(stdout);
	}
	else if(rank == 1)
	{
		//printf("IN rank 1\n");
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process 1\n", x);
		fflush(stdout);
	}
	else if(rank == 2)
	{
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process 2\n", x);
		fflush(stdout);
	}
	else if(rank == 3)
	{
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process 3\n", x);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}