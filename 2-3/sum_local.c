#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

void generate_random(double *input, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    // input[i] = ((double)rand()/(double)RAND_MAX);
    input[i] = 1;
  }
}

struct ls {
  double sum;
  int padding[8192];
};

double real_serial_sum(double *x, size_t size)
{
  double sum_val = 0.0;

  for (size_t i = 0; i < size; i++) {
    sum_val += x[i];
  }

  return sum_val;
}

double opt_local_sum(double *x, size_t size, int thread_num)
{
  struct ls local_sum[thread_num];

  // #pragma omp parallel
  #pragma omp parallel shared(local_sum)
  {
    int id = omp_get_thread_num();
    int st = size / thread_num * id;
    int ed = size / thread_num * (id+1);
    if (ed > size) ed = size;
    printf("id[%d] st[%d] ed[%d]\n", id, st, ed);
    #pragma omp for
    for (size_t i = st; i < ed; i++) {
        local_sum[id].sum += x[i]; // bad cache
        printf("id[%d] sum[%d]\n", id, local_sum[id].sum);
    }

    // int id = omp_get_thread_num();
    // #pragma omp for
    // for (size_t i = id; i < size; i+=thread_num) {
    //     local_sum[id].sum += x[i]; // bad cache
    // }
  }
  
  double sum_val = 0.0;
  for (size_t i = 0; i < thread_num; i++) {
    printf("total: id[%d] sum[%d]\n", i, local_sum[i].sum);
    sum_val += local_sum[i].sum;
  }

  return sum_val;
}

typedef struct { double l_sum; char pad[128]; } p_double; 

// double opt_local_sum(double *x, size_t size, int n_threads) {
//     p_double local_sum[n_threads];
//     #pragma omp parallel shared(local_sum)
//     {
//         int id = omp_get_thread_num();
//         local_sum[id].l_sum = 0.0;
//         #pragma omp for
//             for (size_t i = 0; i<size; i++) {
//                 local_sum[id].l_sum += x[i];
//             }
//     }
//     double sum_val = 0.0;
//     for (int i = 0; i < n_threads; i++) {
//        sum_val += local_sum[i].l_sum;
//     }
//     return sum_val;
// }

int main(int argc, int* argv[]) {
    // int arr_sz = 100000000;
    int arr_sz = 20;

    double* arr = malloc(arr_sz * sizeof(double));

    generate_random(arr, arr_sz);

    double avg_time, start_time, result;
    int n_tests = 1;
    int n_threads = 10;
    int threads[] = {4};
    // int threads[] = {1, 2, 4, 8, 12, 16, 20, 24, 28, 32};
    double time[n_tests], thread_time[n_threads], thread_std[n_threads];    

    double r_serial_sum = real_serial_sum(arr, arr_sz);

    for (int a=0; a<n_threads; a++) {
      omp_set_num_threads(threads[a]);

      // opt_local_sum(arr, arr_sz, threads[a]);

      start_time = omp_get_wtime();
      for (int i=0; i<n_tests; i++) {
        result = opt_local_sum(arr, arr_sz, threads[a]);
        time[i] = omp_get_wtime() - start_time;
      }
      avg_time = (omp_get_wtime() - start_time) / n_tests;

      double sd_sum = 0;
      for (int i=0; i<n_tests-1; i++) {
          //printf("Time: %d, %.15f \n", i, (time[i+1] - time[i]));
          sd_sum += pow((time[i+1] - time[i]) - avg_time, 2);
      }

      double std_dev = sqrt((sd_sum/(n_tests - 1)));

      printf("Average execution time of serial sum with size %d was %fs with a std deviation of %.15f \n", arr_sz, avg_time, std_dev);
      printf("Control: Serial sum = %f, OMP sum = %f \n", r_serial_sum, result);
      
      thread_time[a] = avg_time;
      thread_std[a] = std_dev;
    }

    printf("Threads Time Stdev\n");
    for (int a=0;a < n_threads; a++) {
        printf("%d    %.15f    %.15f \n", threads[a], thread_time[a], thread_std[a]);
    }
    

    free(arr);

    return 0;
}
// gcc -std=c99 -fopenmp a.c
// OMP_NUM_THREADS=32 ./a.out