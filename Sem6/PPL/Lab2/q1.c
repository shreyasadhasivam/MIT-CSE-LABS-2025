#include"mpi.h"
#include<stdio.h>
#include<string.h>

int main(int argc, char * argv[])
{
	int rank, size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	char str[5] ="Hello";
	char str1[5];
	//printf("Test");
	if(rank == 0)
	{
		//printf("In rank 0:\n");
		MPI_Ssend(&str,1,MPI_CHAR,1,1,MPI_COMM_WORLD);
		fprintf(stdout, "I have sent %s from process 0\n", str);
		fflush(stdout);
		MPI_Recv(&str,5,MPI_CHAR,1,2,MPI_COMM_WORLD,&status);
		//strcpy(str1,str);
		fprintf(stdout,"String after toggle: %s\n", str);
	}

	else if(rank == 1)
	{
		//printf("IN rank 1\n");
		MPI_Recv(&str,1,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		//fprintf(stdout,"I have received %s in process 1\n", str);
		fflush(stdout);
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]>='A' && str[i]<='Z')
				str[i] = str[i]+32;
			else if(str[i]>='a' && str[i]<='z')
				str[i] = str[i] - 32;
		}
		//printf("String after toggle in rank 1: %s\n", str);
		MPI_Ssend(&str,5,MPI_CHAR,0,2,MPI_COMM_WORLD);
		
	}
	MPI_Finalize();
	return 0;
}