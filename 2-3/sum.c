#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <omp.h>

void generate_random(double *input, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    input[i] = rand() / (double)(RAND_MAX);
  }
}

double serial_sum(double *x, size_t size)
{
  double sum_val = 0.0;

  for (size_t i = 0; i < size; i++) {
    sum_val += x[i];
  }

  return sum_val;
}

int main(int argc, int* argv[]) {
    int arr_sz = 100000000;

    double* arr = malloc(arr_sz * sizeof(double));

    generate_random(arr, arr_sz);

    double begin = omp_get_wtime();

    serial_sum(arr, arr_sz);

    double end = omp_get_wtime();
    printf("Value is %f \n", end-begin);

    free(arr);

    return 0;
}
// gcc -std=c99 -fopenmp a.c