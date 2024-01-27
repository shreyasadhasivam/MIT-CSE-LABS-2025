#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>

void mpi_check_status ( int mpi_status )
{
    if ( mpi_status != MPI_SUCCESS )
    {
    int len ;
    char err_string [ MPI_MAX_ERROR_STRING ];
    MPI_Error_string ( mpi_status , err_string , & len );
    fprintf ( stderr , " MPI Error : (% d ) % s \n " ,
    mpi_status , err_string );
    exit ( EXIT_FAILURE );
    }
}

int main(int argc, char* argv[]){
    int rank, size, fact=1, factsum, i, err_code;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    err_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0)
        ErrorHandler(err_code);

    int sendVal = rank+1;
    err_code = MPI_Scan(&sendVal, &fact, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    if(rank == 0)
        ErrorHandler(err_code);
    err_code = MPI_Scan(&fact, &factsum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if(rank == 0)
        ErrorHandler(err_code);

    
    printf("Sum of all factorial till %d! = %d\n", rank+1, factsum);

    MPI_Finalize();
    exit(0);
}