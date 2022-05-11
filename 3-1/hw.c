#include "mpi.h"
#include "stdio.h"

int rank, size, len;

int main(int argc, char *argv[])
{
    char version[MPI_MAX_LIBRARY_VERSION_STRING];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_library_version(version, &len);
    printf("Hello, world, I am %d of %d, (%s, %d)\n",
           rank, size, version, len);
}

// salloc --nodes=1 -t 00:02:00 -A edu22.dd2356 -p shared --ntasks-per-node=1 --cpus-per-task=1
// srun -n 4 ./a.out