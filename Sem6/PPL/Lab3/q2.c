#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size, N, M, A[100], B[100], avg, total_sum = 0, total_avg = 0, i, sum = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        N = size;
        printf("Enter M value: ");
        scanf("%d", &M);
        
        printf("Enter %d x %d elements:\n", N, M);
        for (i = 0; i < N*M; i++) {
            scanf("%d", &A[i]);
        }
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(A, M, MPI_INT, B, M, MPI_INT, 0, MPI_COMM_WORLD);
    
    for (i = 0; i < M; i++) {
        sum += B[i];
    }
    avg = sum / M;
    MPI_Allreduce(&avg, &total_avg, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    
    if (rank == 0) {
        total_avg = total_avg / N;
        printf("Average of all processes: %d \n", total_avg);
    }

    MPI_Finalize();
    return 0;
}
