#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	int rank,size,N;
	char ch;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0)
	{
		N=size;
		char str;
		printf("Enter string:\n");
		scanf("%s", str);
	}
	MPI_Scatter(str,1,MPI_CHAR,&ch,1,MPI_CHAR,0,MPI_COMM_WORLD);
	fprintf(stdout,"I have received %d in process %d\n",c,rank);
	fflush(stdout);
	fact = 1;
	for(i=1;i<=c;i++)
		fact = fact*i;
		
	//printf("fact: %d", fact);
	MPI_Gather(&fact,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		fprintf(stdout,"The Result gathered in the root \n");
		fflush(stdout);
		for(i=0; i<N; i++)
			sum += B[i];
		printf("Sum is: %d", sum);
		printf("\n");
	}

	MPI_Finalize();
	return 0;
}