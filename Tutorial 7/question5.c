#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "queue.h"

int main()
{
    // Defining pointers and variables
    struct queue* queue  = malloc(sizeof(struct queue));
    struct proc* process = malloc(sizeof(struct proc));
    char buffer[MAX_LENGTH];
    void* info = malloc(MAX_LENGTH);
    int cpylen;  // Represents index where the buffer needs to start copying from

    // Read processes_q5.txt
    FILE* processes_q5FP = fopen("processes2_q5.txt", "r");

    if (processes_q5FP == NULL) {
        printf("Error");
        exit(0);
    }

    while (fgets(buffer, MAX_LENGTH, processes_q5FP)) {
        // Gathering contents from buffer to be assigned to properties of struct process
        for (int i = 0; i < CATEGORIES - 1; i++) {
            info = strtok(buffer, ", ");

            if (i == 0)
                strcpy(process->name, info);

            else if (i == 1)
                process->priority = atoi(info);

            else
                process->runtime = atoi(info);

            cpylen = strlen(info);
            strcpy(buffer, &buffer[cpylen + 2]);
        }

        process->pid = 0;

        // Pushing process to link list
        push(*process);
    }

    print();

    // Executing processes with priority zero
    printf("\nExecuting processes with priority 0\n");
    queue = head;
    int status;

    while (queue != NULL) {
        if (queue->process.priority == 0) {
            process = delete_name(queue->process.name);

            pid_t pid = fork();

            // Fork failed
            if (pid == -1) {
                printf("Error: Fork process failed");
                exit(0);
            }

            // Child process
            if (pid == 0) {
                printf("\nCHILD");
                execvp(process->name, NULL);
            }

            printf("\nPARENT");
            sleep(process->runtime);
            kill(pid, SIGINT);
            waitpid(-1, &status, 0);
            printProcess(*process);
        }
        queue = queue->next;
    }

    print();

    return 0;
}
