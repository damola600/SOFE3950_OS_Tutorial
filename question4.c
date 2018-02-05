/* Operating Systems Tutorial Acitiviy 3

    Question 4

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Declaring pointers and variables
  char *professor = (char*)calloc(256,sizeof(char));
  int *student_ids;
  int *grades;
  int numOfStudents;

  //Prompting the user for their name and number of students
  printf("Please enter your name: ");
  scanf("%s[^\n]", professor);
  printf("Please enter the number of students to mark: ");
  scanf("%d[^\n]", &numOfStudents);

  //Allocating memory for pStudent_ids and grades
  student_ids = (int*)malloc(numOfStudents * sizeof(int));
  grades = (int*)malloc(numOfStudents * sizeof(int));


  //Freeing memory space for pProfessor, pStudent_ids and pGrades
  free(professor);
  free(student_ids);
  free(grades);

  return 0;
}
