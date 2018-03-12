/* Operating Systems - Tutorial 7 Application Question 1
 *
 * Contains the queue struct
 *
 * Group: Wednesday Group 1
 * Names: Justin Kaipada 100590167 & Anthea Ariyajeyam 100556294
*/

#include "proc.h"

//Struct queue
struct queue
{
  struct proc process;
  struct queue *next;
};