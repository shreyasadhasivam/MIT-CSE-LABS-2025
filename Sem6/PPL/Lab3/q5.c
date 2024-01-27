#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size, N, M, A[100], B[100], i,c,odd=0,even=0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        N = size;
        printf("Enter the array elements:");
        for(i=0;i<N;i++)
            scanf("%d",&A[i]);
    }
    MPI_Scatter(A,1,MPI_INT,&c,1,MPI_INT,0,MPI_COMM_WORLD);
    //printf("%d, rank =%d\n",c,rank);
    if(c%2==0)
    {
        c= 1;
        
    }
    else
    {

        c = 0;
        
    }
    MPI_Gather(&c,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
    
    if(rank ==0)
    {
        printf("Resultant array(A): ");
        for(i = 0;i<N;i++)
        {
            printf("%d  ",B[i]);
        }
        for(i=0;i<N;i++)
        {
            if(B[i]==0)
                odd++;
            else
                even++;
        }
        printf("\nEven(Count) = %d\nOdd(Count) = %d\n", even, odd);
        
    }
    MPI_Finalize();
    return 0;
}