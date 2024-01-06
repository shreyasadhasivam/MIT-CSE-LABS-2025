#include"mpi.h"
#include<stdio.h>
#include<ctype.h>
int main(int argc, char* argv[])
{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	char str[] = "HeLLO";
	int i = rank;
	if(str[i]>='A' && str[i]<='Z')
		str[i] = str[i] +32;
	else if(str[i]>='a' && str[i]<='z')
		str[i] = str[i] -32;
	printf("%d, %s\n", rank,str);
	MPI_Finalize();
}