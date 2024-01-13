#include"mpi.h"
#include<stdio.h>
#include<math.h>
int main(int argc, char * argv[])
{
	int rank, size, x1,x2,x3;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	// x = 5;
	//printf("Test");
	float sd,sum,mean, inter,result;
	if(rank == 0)
	{
		//printf("In rank 0:\n");
	
		MPI_Recv(&x1,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process 0 \n", x);
		MPI_Recv(&x2,1,MPI_INT,2,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process 0 \n", x);
		MPI_Recv(&x3,1,MPI_INT,3,1,MPI_COMM_WORLD,&status);
		printf("I have received %d in process 0 \n", x);
		sum = x1+x2+x3;
		mean = sum/3;
	
		
		sd = pow(x1 - mean,2)+pow(x2 - mean,2)+pow(x3 - mean,2);

	
		
		sd = sd/3;
		printf("sd:%.2f\n", sd);
		
		printf("result : %.2f\n", result);
		fflush(stdout);
	}
	else if(rank == 1)
	{
		x1 = rand()%50;
		//printf("IN rank 1\n");
		MPI_Ssend(&x1,1,MPI_INT,0,1,MPI_COMM_WORLD);
		fprintf(stdout, "I have sent %d from process 1\n", x);
		fflush(stdout);
	}
	else if(rank == 2)
	{
		x2 = rand()%50;		
		MPI_Ssend(&x2,1,MPI_INT,0,1,MPI_COMM_WORLD);
		fprintf(stdout, "I have sent %d from process 2\n", x);
		fflush(stdout);
	}
	else if(rank == 3)
	{
		x3 = rand()%50;
		MPI_Ssend(&x3,1,MPI_INT,0,1,MPI_COMM_WORLD);
		fprintf(stdout, "I have sent %d from process 3\n", x);

		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}