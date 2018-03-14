/* Operating Systems - Tutorial 7 Application Question 1
 *
 * Group: Wednesday Group 1
 * Names: Justin Kaipada 100590167 & Anthea Ariyajeyam 100556294
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//Defining Macros
#define CATEGORIES 4




int main()
{
  //Initializing Variables
  char buffer[MAX_LENGTH];              // Used to store the contents from processes.txt 
  void *info = malloc(MAX_LENGTH);      // Used to contain specific information (i.e. process name, priority, pid and runtime) from process.txt to be placed in struct process
  int cpylen;                           // Represents index where the buffer needs to start copying from
  struct proc process;                  // Represents the process to be added into the link list
  
  //Read process.txt
  FILE * processFD = fopen("processes.txt","r");

  if (processFD == NULL)
  {
    printf("Error");
    exit(0);
  }

  while (fgets(buffer, MAX_LENGTH, processFD))
  {
    //Gathering contents from buffer to be assigned to properties of struct process
    for (int i = 0; i < CATEGORIES; i++)
    {
      info = strtok(buffer, ", ");
      
      if (i == 0)
        strcpy(process.name, info);

      else if (i == 1)
        process.priority = atoi(info);

      else if (i == 2)
        process.pid = atoi(info);

      else
        process.runtime = atoi(info);

      cpylen = strlen(info);
      strcpy(buffer,&buffer[cpylen+2]);
    }

    //Pushing process to link list
    push(process);
    
  }
  //Printing process
  print();
  return 0;
}
