#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	/* -------------------------------------------------------------------------------------------
		MPI Initialization 
	--------------------------------------------------------------------------------------------*/
	MPI_Init(&argc, &argv);

	int size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Status stat;

	if(size != 2){
		if(rank == 0){
			printf("This program requires exactly 2 MPI ranks, but you are attempting to use %d! Exiting...\n", size);
		}
		MPI_Finalize();
		exit(0);
	}

	/* -------------------------------------------------------------------------------------------
		Loop from 8 B to 1 GB
	--------------------------------------------------------------------------------------------*/

	for(int i=0; i<=27; i++){

		long int N = 1 << i;
	
   	 	// Allocate memory for A on CPU
		double *A = (double*)malloc(N*sizeof(double));

		// Initialize all elements of A to 0.0
		for(int i=0; i<N; i++){
			A[i] = 0.0;
		}
	
		int tag1 = 10;
		int tag2 = 20;
	
		int loop_count = 50;

		// Warm-up loop
		for(int i=1; i<=5; i++){
			if(rank == 0){
				MPI_Send(A, N, MPI_DOUBLE, 1, tag1, MPI_COMM_WORLD);
				MPI_Recv(A, N, MPI_DOUBLE, 1, tag2, MPI_COMM_WORLD, &stat);
			}
			else if(rank == 1){
				MPI_Recv(A, N, MPI_DOUBLE, 0, tag1, MPI_COMM_WORLD, &stat);
				MPI_Send(A, N, MPI_DOUBLE, 0, tag2, MPI_COMM_WORLD);
			}
		}

		// Time ping-pong for loop_count iterations of data transfer size 8*N bytes
		double start_time, stop_time, elapsed_time;
		start_time = MPI_Wtime();
	
		for(int i=1; i<=loop_count; i++){
			if(rank == 0){
				MPI_Send(A, N, MPI_DOUBLE, 1, tag1, MPI_COMM_WORLD);
				MPI_Recv(A, N, MPI_DOUBLE, 1, tag2, MPI_COMM_WORLD, &stat);
			}
			else if(rank == 1){
				MPI_Recv(A, N, MPI_DOUBLE, 0, tag1, MPI_COMM_WORLD, &stat);
				MPI_Send(A, N, MPI_DOUBLE, 0, tag2, MPI_COMM_WORLD);
			}
		}

		stop_time = MPI_Wtime();
		elapsed_time = stop_time - start_time;

		long int num_B = 8*N;
		long int B_in_GB = 1 << 30;
		double num_GB = (double)num_B / (double)B_in_GB;
		double avg_time_per_transfer = elapsed_time / (2.0*(double)loop_count);

		if(rank == 0) printf("%10li\t%15.9f\n", num_B, avg_time_per_transfer);

		free(A);
	}

	MPI_Finalize();

	return 0;
}

// salloc --nodes=1 -t 00:02:00 -A edu22.dd2356 -p shared --ntasks-per-node=1 --cpus-per-task=1
// srun -n 2 ./a.out

// intra
//          8          0.000000659
//         16          0.000000277
//         32          0.000000250
//         64          0.000000250
//        128          0.000000269
//        256          0.000000316
//        512          0.000000397
//       1024          0.000000587
//       2048          0.000000806
//       4096          0.000001169
//       8192          0.000000723
//      16384          0.000001120
//      32768          0.000001882
//      65536          0.000003300
//     131072          0.000006397
//     262144          0.000011787
//     524288          0.000020343
//    1048576          0.000034367
//    2097152          0.000059060
//    4194304          0.000112930
//    8388608          0.000463055
//   16777216          0.001451386
//   33554432          0.002616607
//   67108864          0.004524519
//  134217728          0.008278919
//  268435456          0.015774290
//  536870912          0.031172383
// 1073741824          0.061974570

// inter
//          8          0.000001917
//         16          0.000001925
//         32          0.000001915
//         64          0.000001899
//        128          0.000001941
//        256          0.000002546
//        512          0.000002597
//       1024          0.000002813
//       2048          0.000003186
//       4096          0.000003978
//       8192          0.000004856
//      16384          0.000007051
//      32768          0.000009089
//      65536          0.000012284
//     131072          0.000018189
//     262144          0.000029244
//     524288          0.000052647
//    1048576          0.000095457
//    2097152          0.000181172
//    4194304          0.000352387
//    8388608          0.000694602
//   16777216          0.001379335
//   33554432          0.002748637
//   67108864          0.005486895
//  134217728          0.010963268
//  268435456          0.021915812
//  536870912          0.060550272
// 1073741824          0.121954473