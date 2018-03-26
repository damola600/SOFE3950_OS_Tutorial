/* Operating Systems - Tutorial Activity 9; Question 4
 * 
 * Group 1 (Wednesday)
 * Names: Anthea Ariyajeyam (100556294) Justin Kaipada 100590167
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define DEM 100     // The deminsions of the matrix

/* printMatrix
 *
 * prints the contents in the matrix
 */
void printMatrix(int matrix[DEM][DEM])
{
    for (int i = 0; i < DEM; i++)
    {
        for (int j = 0; j < DEM; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n\n");
}

int main()
{
    //Declaring arrays
    int a[DEM][DEM];
    int b[DEM][DEM];
    int result[DEM][DEM];

    //Initialize the arrays a, b and result
    for (int i = 0; i < DEM; i++)
    {
        for (int j = 0; j < DEM; j++)
        {
            a[i][j] = i + j;
            b[i][j] = i + j;
            result[i][j] = 0;
        }
    }

    printf("\nBefore multiplication matrix a and b are:\n");
    printMatrix(a);
    

    //Performing Matrix Multipliction using openMP
    #pragma omp parallel for
        for(int i = 0; i < DEM; i++)
        {
            for (int j = 0; j < DEM; j++)
            {
                for (int l = 0; l < DEM; l++)
                {
                    result[i][j] += (a[i][l] * b[l][j]);
                }
            }
        }
    
    //The result of the matrix
    printf("Results of matrix a time matrix b\n");
    printMatrix(result);
    return 0;
}