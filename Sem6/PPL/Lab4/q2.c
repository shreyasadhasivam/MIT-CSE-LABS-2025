
#include <stdio.h>
#include "mpi.h"
int main (int argc, char *argv[]) {
	int rank, size;
	float area, area1;
	float x, y;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	x = (float)rank/size;
	y = 4 / (1 + x * x);
	area = (1 / (float)size) * y;
	MPI_Reduce(&area, &area1, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0) {
		printf("The value of PI is: %f\n", area1);
	}
	MPI_Finalize();
	return 0;
}