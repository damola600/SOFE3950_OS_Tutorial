#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int nthreads, thread_num;
    const int n      = 100000000;
    double y[100000000] = {0};
    double x         = 0;
    if (argc < 2) {
        printf("Please enter the number of threads to use\n");
        exit(1);
    } else {
        nthreads = atoi(argv[1]);
    }
#ifdef _OPENMP
    omp_set_num_threads(nthreads);
#endif
#pragma omp parallel for reduction(+ : x)
    for (int i = 0; i < n; ++i) {
        x += i * (1 / (n + 1));
        y[i]       = exp(x) * cos(x) * sin(x) * sqrt(5 * x + 6.0);
        thread_num = omp_get_thread_num();
        printf("This thread = %d\n", thread_num);
        printf("x is %.*f\n", 10, x);
        printf("y is %.*f\n", 10, y[i]);
    } /* Parellel section ends */
    return 0;
}
