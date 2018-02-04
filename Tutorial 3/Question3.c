#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void save_student(struct Student student)
{
    FILE* input = fopen("students.txt", "a"); /* Open file in append mode */
    if (input == NULL) {
        printf("File students.txt could not be opened!!.. exiting...");
        exit(EXIT_FAILURE);
    }
    fprintf(input, "%s,%d,%d\n", student.student_id, student.age, student.start_year);
    fclose(input);  // Close the file
    return;
}

int main()
{
    struct Student someone;
    printf("Enter your student id: ");
    scanf("%9s", someone.student_id);
    printf("Enter your age: ");
    scanf("%d", &someone.age);
    printf("Enter the year you started school in UOIT: ");
    scanf("%d", &someone.start_year);

    save_student(someone);
    return 0;
}
