/*
  Create a program that does the following
  - Creates an array of 10 integer values from 1 to 10
  - Has a loop that iterates through the array and prints each integer
    in the array.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[10];
    /* Populate the array */
    for (int i = 0; i < 10; ++i) {
        array[i] = i + 1;
    }
    /* Print the array to stdout */
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
