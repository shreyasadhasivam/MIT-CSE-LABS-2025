#include"mpi.h"
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int size,rank,x;
	x = 4;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("The power of the process %d is %f\n",rank, pow(x,rank));
	MPI_Finalize();
	return 0;

}