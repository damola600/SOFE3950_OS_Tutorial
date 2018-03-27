#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nthreads = 3;
    const int n  = 100000000;
    double norm  = 0;
    double x[100000000];
    /* Initialize the array randomly  */
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        x[i] = rand();
    }

    /* Compute serially  */
    double start = omp_get_wtime();
    for (int i = 0; i < n; ++i) {
        norm += fabs(x[i]);
    }
    double stop                 = omp_get_wtime();
    double time_for_serial_loop = stop - start;
    printf("Norm calculated by serial loop is %.*f\n", 5, norm);


    /* Compute in parallel */
    start = omp_get_wtime();
#ifdef _OPENMP
    omp_set_num_threads(nthreads);
#endif
    norm = 0;
#pragma omp parallel for reduction(+ : norm)
    for (int i = 0; i < n; ++i) {
        norm += fabs(x[i]);
    } /* Parellel section ends */
    stop                          = omp_get_wtime();
    double time_for_parallel_loop = stop - start;

    printf("Norm calculated by parallel loop is %.*f\n", 5, norm);
    printf("Time taken by the serial loop is %.*f\n", 10, time_for_serial_loop);
    printf("Time taken by the parallel loop is %.*f\n", 10, time_for_parallel_loop);
    printf("Time difference is %.*f\n", 10, time_for_serial_loop - time_for_parallel_loop);
    return 0;
}
