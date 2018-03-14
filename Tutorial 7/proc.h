/* Operating Systems - Tutorial 7 Application Question 1
 *
 * Contains the proc struct
 * 
 * Group: Wednesday Group 1
 * Names: Justin Kaipada 100590167 & Anthea Ariyajeyam 100556294
*/

//Defining Macro
#define MAX_LENGTH 265
//Defining Macros
#define CATEGORIES 4

//Struct proc
struct proc
{
  char name [MAX_LENGTH];
  int priority;
  int pid;
  int runtime;
};

void printProcess(struct proc process)
{
  printf("Name: %s \t Priority: %i \t Pid: %i \t Runtime: %i\n",process.name, process.priority, process.pid, process.runtime);
}