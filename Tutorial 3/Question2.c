/**
 * Learn about fscaf and fopen
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[10];
    FILE* input = fopen("question2.txt", "r"); /* Open file in read mode */
    if (input == NULL) {
        printf("File question2.txt could not be opened!!.. exiting...");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 10; ++i) {
        fscanf(input, "%d", &array[i]);
    }
    fclose(input);  // Close the file

    printf("Contents of the file: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
