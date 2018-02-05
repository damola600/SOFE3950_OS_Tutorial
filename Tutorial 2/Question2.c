/*
  Create a program that does the following
  - Creates an array of the following 5 double values 1.2, 5.5, 2.1, 3.3, 3.3
  - Checks if the current value is greater than, less than, or the
    same as the previous value and for each case prints either
    "greater than", "less than", or "the same"
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double array[5] = {1.2, 5.5, 2.1, 3.3, 3.3};
    double previous = array[0];
    for (int i = 0; i < 5;) {
        if (array[i] > previous)
            printf("previous(%f) is less than %f\n", previous, array[i]);
        else if (array[i] < previous)
            printf("previous(%f) is greater than %f\n", previous, array[i]);
        else
            printf("previous(%f) is equal to %f\n", previous, array[i]);
        previous = array[i];
        ++i;
    }
    printf("\n");
    return 0;
}
