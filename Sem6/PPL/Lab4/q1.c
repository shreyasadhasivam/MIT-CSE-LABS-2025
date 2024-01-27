#include <stdio.h>
#include "mpi.h"
int main(int argc, char* argv[])
{
	int rank,size,fact=1, sum=0,prod=1;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int rank1 = rank+1;
	MPI_Scan(&rank1, &prod,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
	MPI_Reduce(&prod,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank == 0){
		printf("The sum is :%d\n",sum);
	}
	MPI_Finalize();
	return 0;
}