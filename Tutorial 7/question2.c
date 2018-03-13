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

//Global variables
struct queue *head;


/*push()
 * Adds process from parameter to the beginning of the link list
 * 
*/        
void push(struct proc process)
{
  struct queue *temp = malloc (sizeof(struct queue));
  
  temp->process = process;

  temp->next = head;

  head = temp;

}

/* print()
 * Prints the queue struct
*/
void print()
{

  struct queue *temp = head;

  while (temp->next != NULL)
  {
    printf("Name: %s \t Priority: %i \t Pid: %i \t Runtime: %i\n", temp->process.name, temp->process.priority,temp->process.pid, temp->process.runtime);
    temp = temp->next;
  }
}



/* pop()
 * removes and returns the first process in the link list
*/
struct proc* pop()
{
    //Declaring pointers and variables
    struct queue *temp = malloc(sizeof(struct queue));
    temp = head;                                                      //Used to traverse through the list
    struct proc *firstItem = malloc (sizeof(struct proc));           //Used to point to the first item in the list and return that value
    int count = 0;                                                   //Counts the number of items to tranverse in order to get to the first item

    //If there is only one item in the list 
    if (temp->next == head)
    {
      *firstItem = temp->process;
      head = NULL;
      return firstItem;
      
    }
      
    //If there is more than one item in the list
    else
    {
      //Finds the location of the item
      while (temp ->next != NULL)
      {
        temp = temp->next;
        count++;
      }
    
      *firstItem = temp->process; 
      temp->next = NULL; 
    
      //Removes the item that is popped from the link list
      temp = head;

      for (int i = 0; i < count - 1; i++)
      {
        temp = temp->next;
      }
    
      temp->next = NULL;

      return firstItem;
    }
     
}


/* delete_name
 * removes an item in the link list according to the process name and returns it. If the name is not found, it returns NULL
*/
struct proc* delete_name(char *name)
{
    
    //Declaring pointers and variables
    struct queue *temp = head;                                //Used to hold the first half of the list (i.e. before item with char* name )
    struct queue *temp1 = head;                               //Used to hold the second half of the list (i.e. after item with char* name)
    struct proc *process = malloc(sizeof(struct queue));      //Stores the process being returned by the function (i.e. the name of the item being deleted)
    char * tempName = head->process.name;                     //Stores the name of the process 
    int count = 0;                                            //Counts the number of items to tranverse in order to get to the item being deleted

    //Finding the location of the item to be deleted
    while (strcmp(tempName, name) != 0 && temp->next != NULL)
    {
        temp = temp->next;
        tempName = temp->process.name;
        count++;
    }
    
    //If process does not exist
    if (temp->next == NULL)
    {
        process = NULL;
        return process;
    }
    
    //If process does exist
    else
    {
      process = &temp->process;

      for (int i = 0; i < count - 1; i++)
      {
        temp1 = temp1->next;
      }
      
      temp1->next = temp->next;

      temp = temp1;
      
      return process;
    }
           
}


/* delete_pid
 * removes an item in the link list according to the process pid and returns it. If the pid is not found, it returns Null 
*/
struct proc* delete_pid(int pid)
{
    //Declaring pointers and variabels
    struct queue *temp = head;                                //Used to hold the first half of the list (i.e. before item with int pid)
    struct queue *temp1 = head;                               //Used to hold the second half of the list (i.e. after item with int pid)
    struct proc *process = malloc(sizeof(struct queue));      //Used to store the value being returned by function
    int count = 0;                                            //Counts the number of items to tranverse in order to get to the item being deleted
    
    //Finds the processes location
    while (pid != temp->process.pid && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    //If the process does not exist
    if (temp->next == NULL)
    {
        process = NULL;
        return process;
    }
    
    //If the process exists
    else
    {
        process = &temp->process;

        for (int i = 0; i < count - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp1->next = temp->next;

        return process;
    }
           
}

void message (struct proc *process)
{
  if (process != NULL)
    printf("\nDeleted Process: %s \n", process->name);
  else
    printf("Could not find process\n");
  print();
  printf("\n");
}


int main()
{
  //Initializing Variables
  char buffer[MAX_LENGTH];              // Used to store the contents from processes.txt 
  void *info = malloc(MAX_LENGTH);      // Used to contain specific information (i.e. process name, priority, pid and runtime) from process.txt to be placed in struct process
  int cpylen;                           // Represents index where the buffer needs to start copying from
  int count = 0;
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
    count++;
  }
  
  printf("Items pushed in link list\n");
  print();

  //Deleting process named emacs
  char *processName = "emacs";
  struct proc *pro = delete_name(processName);
  message(pro);
  

  //Deleting process with pid 12235
  pro = delete_pid(12235);
  message(pro);
  printf("\n");
  

  //Popping processes
  printf("Popping items from list\n");

  for(int i = 0; i < count-2; i++)
  {
    pro = pop();
    printf("Name: %s \t Priority: %i \t Pid: %i \t Runtime: %i\n",pro->name, pro->priority, pro->pid, pro->runtime);      //WORKING
  }
  print();  //Noting is being printed therefore items are not in list
  
  return 0;
}
