#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    #pragma omp parallel
    {
        int id = 0;
        int np = 1;
        printf("Hello %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
// gcc -fopenmp hw.c; OMP_NUM_THREADS=4 ./a.out
// omp_set_num_threads
// num_threads ref:https://docs.microsoft.com/en-us/cpp/parallel/openmp/reference/openmp-clauses?view=msvc-170#num-threads