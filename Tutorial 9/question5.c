/* Operating Systems - Tutorial Activity 9; Question 5
 * 
 * Group 1 (Wednesday)
 * Names: Anthea Ariyajeyam (100556294) Justin Kaipada 100590167
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main(int argc, char *argv[])
{
    //Make sure there is one numerical value entered by the user
    if (argc >2 || argc == 1)
    {
        printf("Please enter one number");
        exit(0);
    }

    //Declaring Variables and file pointers
    int numOfThreads = atoi(argv[1]);
    float n = 100000000;
    float x,y;
    FILE * calculationsFP;
    
    #ifdef _OPEN
    omp_set_num_threads(numOfThreads);
    #endif

    //Calculate step size
    float dx = 1/(n+1);

    //Opening file
    calculationsFP = fopen("calculations.txt", "w");

    //Performing Calucaltions and writing the results and current index for every 1 millionth calculation
    #pragma omp parallel private(x)
    
        for (int i = 0; i < (int)n; i++)
        {
            x = i*dx;
            y = exp(x) * cos(x) * sin(x) *sqrt(5 * x + 6.0);

            //Write to calculations.txt
            if (i % 1000000 == 0 && i != 0)
            {   
                #pragma omp critical 
                {
                    #ifdef _OPENMP
                    fprintf(calculationsFP, "i: %d \t x: %f \t y: %f \t \n", i,x,y );
                    #endif
                }
            }
        }
    
    //Closing file
    fclose(calculationsFP);

    return 0;
}