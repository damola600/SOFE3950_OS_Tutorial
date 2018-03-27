#include <omp.h>
#include <stdio.h>

int main()
{
    printf("This statement will always print.\n");
    /*
       This section will only print if omp is usable and working. the
       ifdef checks if the macro is defined and it is defined if the
       preprocessor finds open mp
    */
#ifdef _OPENMP
    printf("This statement will only print when compiled with \"-fopenmp\"\n");
#endif
    return 0;
}
