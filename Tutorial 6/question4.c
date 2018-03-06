/* Operating Systems - Tutorial Activity 6 Question 4

  Names: Anthea Ariyajeyam (100556294) Justin Kaipada (100590167)
  Section: Wednesdays Group: 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

//Defining semaphores
sem_t semTask;
sem_t semFull;
sem_t semEmpty;


#define NUMBERS 10

//Global Array
int buffer[5];
int low = 0;
int high = 0;
int sval = 0;

void printbuffer()
{
  printf("Contents in buffer\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%i ", buffer[i]);
  }
  printf("\n\n");
}



//producer function
void *producer(void * input)
{
    for (int i = 0; i< NUMBERS; i++)
    {
      srand(time(NULL));

      sleep(rand()%3);

      sem_wait(&semEmpty);
      sem_wait(&semTask);
      buffer[high] = ((int *)input)[i];
      printf("Produced <%i>\n",((int *)input)[i]);
      printbuffer();
      high++;
      if (high == 5)
        high = 0;

      sem_post(&semTask);
      sem_post(&semFull);

    }

  pthread_exit(NULL);
}

//Consumer function
void *consumer()
{

  for (int i = 0; i <NUMBERS; i++)
  {
    srand(time(NULL));

    sleep(rand()%10);
    sem_wait(&semFull);
    sem_wait(&semTask);

    printf("Consumed <%d>\n", buffer[low]);

    buffer[low] = 0;
    low++;
    if (low == 5)
      low = 0;

    sem_post(&semTask);
    sem_post(&semEmpty);
    printbuffer();


  }

  pthread_exit(NULL);
}



int main() {

  //Initalizing the semaphores
  sem_init(&semTask,0,1);
  sem_init(&semFull,0,0);
  sem_init(&semEmpty,0,5);

  //Prompts user for 10 numbers
  int input[NUMBERS] = {0};

  printf("Enter 10 numbers \n");
  for (int i = 0; i < NUMBERS; i++)
  {
    scanf("%i[^\n]", &input[i]);
  }

  //Creating threads
  pthread_t tidProd;
  pthread_t tidCon;

  pthread_attr_t attr;
  pthread_attr_init(&attr);

  //Thread for producer
  pthread_create(&tidProd, &attr, producer,&input);
  pthread_create(&tidCon, &attr, consumer,NULL);


  //Wait for threads to finish
  pthread_join(tidProd,NULL);
  pthread_join(tidCon,NULL);

  printf("\n\n\nFinal ");
  printbuffer();
  printf("\n\n");

  //Destroying the semaphore
  sem_destroy(&semTask);
  sem_destroy(&semFull);
  sem_destroy(&semEmpty);

  return 0;
}
