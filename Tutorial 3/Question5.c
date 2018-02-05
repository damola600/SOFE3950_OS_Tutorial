/* Operating Systems Tutorial Acitiviy 3

    Question 5

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "grade.h"


void grade_students (struct grade *grades,int num_students)
{
  //Declaring variables and file pointers
  int sum = 0;
  double diff; // differnce
  double average;
  double stdDeviation; //standard Deviation
  int studentMark;
  FILE *fpointer = fopen("grade.txt","w");

  //Puting marks and names into file
  for (int i = 0; i < num_students; i++)
  {
    sum = sum + (grades + i)->mark;
    fprintf(fpointer, "Student id: %i \t mark: %i \n", (grades + i)->student_id, (grades + i)->mark);
  }

  //Calculating average and standard Deviation
  average = (double) sum / num_students;

  sum = 0;
  for (int i = 0; i < num_students; i++)
  {
      studentMark = (grades + i)->mark;
      diff = pow(studentMark - average, 2);
      sum = sum + diff;
  }

  stdDeviation =  sqrt(diff/(num_students - 1));

  //Printing mean and standard Deviation into file and closing it
  fprintf(fpointer, "\n\n Average: %f \t standard Deviation: %f\n", average, stdDeviation);

  fclose(fpointer);
}



int main()
{
  //Declaring pointers and variables
  char *professor = (char*)calloc(256,sizeof(char));
  struct grade *grades;
  int num_students;

  //Prompting the user for their name and number of students
  printf("Please enter your name: ");
  scanf("%s[^\n]", professor);
  printf("Please enter the number of students to mark: ");
  scanf("%d[^\n]", &num_students);

  //Allocating memeory for pGradeStruct
  grades = (struct grade*)malloc(num_students * sizeof(struct grade));

  //Storing student grades in grade sturct
  for (int i = 0; i < num_students; i++)
  {
    printf("Student id: ");
    scanf("%i[^\n]",&(grades + i)->student_id);

    printf("Mark: ");
    scanf("%i[^\n]", &(grades + i)->mark);
  }

  //Calling Grades Function
  grade_students(grades,num_students);

  //Freeing memory space for pProfessor and pGrades
  free(professor);
  free(grades);

  return 0;

}
