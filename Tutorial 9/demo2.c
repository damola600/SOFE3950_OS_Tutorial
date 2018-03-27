#include <omp.h>
#include <stdio.h>
int main()
{
    int num = 0;  // Watch out for race conditions!
    int thread_num, nthreads = 16;
#ifdef _OPENMP
    omp_set_num_threads(nthreads);
#endif
    printf("Testing OpenMP, you should see each thread print...\n");
    /* This section will be ran parallel util the end of the block */
#pragma omp parallel
    {
        thread_num = omp_get_thread_num();
        /* This is the critical section until the end of the block,
           only one thread runs it at a time preventing race
           cinditions
        */
#pragma omp critical
        {
#ifdef _OPENMP
            num += 1;  // THREAD SAFE INCREMENT
            printf("This thread = %d, num = %d\n", thread_num, num);
#endif
        } /* Critcal section ends */
    }     /* Parellel section ends */
    return 0;
}
