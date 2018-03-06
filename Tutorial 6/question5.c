/* Operating Systems - Tutorial Activity 6 Question 5

  Names: Anthea Ariyajeyam (100556294) Justin Kaipada (100590167)
  Section: Wednesdays Group: 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>

#define NUMBERS 5
#define MAX_LEN 256

//Global variables
int total_sum = 0;
sem_t semTask;


//Factorial Function
void *FactorialOperation (void *numberArg)
{
  int factorial = 1;
  int number = *((int*)numberArg);

  //Calculate Factorial
  if (number == 0 || number == 1)
    factorial = 1;
  else
    {
      for (int i = 1; i <= number; i++)
      {
        factorial = factorial * i;
      }
    }

    //Adds to total_sum
    sem_wait(&semTask);
    total_sum = total_sum + factorial;
    printf("number: %i\t  factorial: %i\t  total_sum: %i\n", number, factorial, total_sum);
    sem_post(&semTask);


    pthread_exit(NULL);
}


int main()
{
  //Declaring variables, arrays and pointers
  pid_t pid;
  int input[NUMBERS] = {0};
  int values[NUMBERS];
  int count = 0;
  char buffer[MAX_LEN];



  //Prompts the user for five numbers
  printf("Enter 5 numbres:\n" );
  for (int i = 0; i < NUMBERS; i++)
  {
    scanf("%i[^\n]", &input[i]);
  }

  //Writing contents in input to numbers.txt
  FILE *numbersFP = fopen("numbers.txt","w");

  for (int i = 0; i < NUMBERS; i++)
  {
    fprintf(numbersFP, "%i\n", input[i]);
  }

  fclose(numbersFP);



  //Creating child process
  pid = fork();

  //If process failded to be created
  if(pid < 0)
  {
    printf("Fork Failed\n");
    exit(0);
  }
  //Child Process
  else if (pid == 0)
  {
    printf("\n\nResults of factorial for each thread and the total_sum\n" ); //Delete after

    //Reads contents in numbers.txt
    FILE *numbers2FP = fopen("numbers.txt","r");
    while(fgets(buffer, MAX_LEN, numbers2FP) != NULL)
    {
      values[count] = atoi(buffer);
      count++;
    }
    fclose(numbers2FP);

    //Initalizing semaphore
    sem_init(&semTask,0,1);

    //Create 5 threads for each index in values arrray
    pthread_t tid_list[NUMBERS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < NUMBERS; i++)
    {
      pthread_create(&(tid_list[i]), &attr, FactorialOperation, &(values[i]));
    }


    //Waiting for threads to finish
    for (int i = 0; i <NUMBERS; i++)
    {
      pthread_join(tid_list[i], NULL);
    }

    //Destroying semaphore
    sem_destroy(&semTask);

    //Writing total_sum into sum.txt
    FILE *sumFP = fopen("sum.txt","w");

    fprintf(sumFP, "%i\n", total_sum);

    fclose(sumFP);

    exit(0);
  }

  //Parent process
  else
  {
    wait(NULL);

    //Reads contents in sum.txt
    FILE *sum2FP = fopen("sum.txt","r");

    while(fgets(buffer, MAX_LEN, sum2FP) != NULL)
    {
      printf("\n\nThe total sum is: %i\n", atoi(buffer));
    }

    fclose(sum2FP);
    exit(0);
  }



  return 0;
}
