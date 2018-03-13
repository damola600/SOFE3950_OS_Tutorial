#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int status; /* For waitpid */
    int pid = fork();
    if (pid == -1) {
        printf("Error: Fork process failed");
        exit(-1);
    } else if (pid == 0) {
        /* Child process */
        execvp("./process", NULL);
    }
    sleep(5);
    kill(pid, SIGTSTP); /* Suspend it */
    sleep(10);
    kill(pid, SIGCONT); /* Resume it */
    sleep(5);
    kill(pid, SIGINT); /* Interrupt it */
    waitpid(-1, &status, 0);
    return 0;
}
