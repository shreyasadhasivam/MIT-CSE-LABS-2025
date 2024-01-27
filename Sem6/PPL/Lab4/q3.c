#include <stdio.h>
#include "mpi.h"
int main(int argc, char* argv[])
{
	int rank, size,  ele, result;
    int mat[3][3];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0)
	{
		printf("Enter the elements for 3x3 matrix:\n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				scanf("%d",&mat[i][j]);
		}
		printf("Enter element to be searched: ");
		scanf("%d", &ele);
	}
	int sMat[3];
    MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(mat, 3, MPI_INT, sMat, 3, MPI_INT, 0, MPI_COMM_WORLD);
    // for(int i=0;i<3;i++)
    // {
    // 	    printf("%d \t", sMat[i]);

    // }
    // printf("rank: %d\n", rank);
    int res = 0;
    for(int i=0;i<3;i++){
        if(sMat[i] == ele)
            res++;
    }
    MPI_Reduce(&res, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0){
        printf("Total number of occurences is: %d\n", result);
    }

    MPI_Finalize();
    
	return 0;
}