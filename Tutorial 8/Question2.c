#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "queue.h"

#define MEMORY 1024

int main()
{
    Queue* priority       = NULL;
    Queue* secondary      = NULL;
    Queue* temp           = NULL;
    int avail_mem[MEMORY] = {0};

    FILE* file = fopen("processes_q2.txt", "r");
    if (file == NULL) {
        printf("Error\n");
        exit(1);
    }

    int eof;
    Proc proc;
    while (eof != EOF) {
        eof          = fscanf(file, "%s%*c %d%*c %d%*c %d", proc.name, &proc.priority, &proc.memory,&proc.runtime);
        proc.pid     = 0;
        proc.address = 0;
        if (proc.priority == 0) {
            temp = enqueue(priority, proc);
            if (priority == NULL) priority = temp;
        } else {
            temp = enqueue(secondary, proc);
            if (secondary == NULL) secondary = temp;
        }
    }
    fclose(file);

    printf("Primary\n");
    temp = priority;
    while (temp != NULL) {
        printf("Name:%s Pid:%d Add:%d Pri:%d Mem:%d Run:%d\n", temp->value.name, temp->value.pid,
               temp->value.address, temp->value.priority, temp->value.memory, temp->value.runtime);
        temp = temp->next;
    }

    printf("\nSecondary\n");
    temp = secondary;
    while (temp != NULL) {
        printf("Name:%s Pid:%d Add:%d Pri:%d Mem:%d Run:%d\n", temp->value.name, temp->value.pid,
               temp->value.address, temp->value.priority, temp->value.memory,
	       temp->value.runtime);
        temp = temp->next;
    }

    return 0;
}
