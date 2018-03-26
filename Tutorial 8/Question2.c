#define _POSIX_SOURCE
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
    int pid;
    int status; /* For waitpid */

    FILE* file = fopen("processes_q2.txt", "r");
    if (file == NULL) {
        printf("Error: can't open file for reading\n");
        exit(1);
    }

    /* Read all the processes from the txt file */
    int eof;
    Proc proc;
    while (eof != EOF) {
        eof          = fscanf(file, "%s%*c %d%*c %d%*c %d", proc.name, &proc.priority, &proc.memory,
                     &proc.runtime);
        proc.pid     = 0;
        proc.address = 0;
        proc.suspended = 0;
        if (proc.priority == 0) {
            temp = enqueue(priority, proc);
            if (priority == NULL) priority = temp;
        } else {
            temp = enqueue(secondary, proc);
            if (secondary == NULL) secondary = temp;
        }
    }
    fclose(file);

    /* Run all the priority processes */
    while (priority != NULL) {
        printf("Running--> Name:%s Pid:%d Priority:%d Memory:%d Runtime:%d\n", priority->value.name,
               priority->value.pid, priority->value.priority, priority->value.memory,
               priority->value.runtime);
        /* Simulate using memory by modifying the array */
        priority->value.address = 0;
        for (int i = 0; i < priority->value.memory; ++i) avail_mem[i] = 1;
        pid = fork();
        if (pid == -1) {
            printf("Error: Fork process failed\n");
            exit(-1);
        } else if (pid == 0) {
            /* Child process */
            execvp("./process", NULL);
        }
        sleep(priority->value.runtime);
        kill(pid, SIGINT); /* Interrupt it */
        waitpid(-1, &status, 0);
        /* Simulate freeing memory by modifying the array */
        for (int i = 0; i < priority->value.memory; ++i) avail_mem[i] = 0;
        priority = dequeue(priority);
    }

    /* Run all the secondary processes */
    while (secondary != NULL) {
        printf("Running--> Name:%s Pid:%d Priority:%d Memory:%d Runtime:%d\n",
               secondary->value.name, secondary->value.pid, secondary->value.priority,
               secondary->value.memory, secondary->value.runtime);
        /* Simulate using memory by modifying the array */
        secondary->value.address = 0;
        for (int i = 0; i < secondary->value.memory; ++i) avail_mem[i] = 1;
        pid = fork();
        if (pid == -1) {
            printf("Error: Fork process failed\n");
            exit(-1);
        } else if (pid == 0) {
            /* Child process */
            if (secondary->value.suspended == 1)
                kill(secondary->value.pid, SIGCONT); /* resume it */
            else
                execvp("./process", NULL);
        }
        sleep(1);
        if (secondary->value.runtime == 1) {
            kill(pid, SIGINT); /* Interrupt it */
            /* Simulate freeing memory by modifying the array */
            for (int i = 0; i < secondary->value.memory; ++i) avail_mem[i] = 0;
            secondary = dequeue(secondary);
            waitpid(-1, &status, 0);
        } else {
            kill(pid, SIGTSTP); /* pause it */
            /* Simulate freeing memory by modifying the array */
            for (int i = 0; i < secondary->value.memory; ++i) avail_mem[i] = 0;
            Proc temp_proc = secondary->value;
            temp_proc.runtime -= 1;
            temp_proc.suspended = 1;
            temp_proc.pid       = pid;
            temp                = enqueue(secondary, temp_proc); /* Add the process back to queue */
            if (secondary == NULL) secondary = temp;
            secondary = dequeue(secondary);
        }
    }

    return 0;
}
