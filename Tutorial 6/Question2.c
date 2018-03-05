#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> /* For sleep() */

int main()
{
    int pid;
    int status;
    pid = fork();
    if (pid == 0) /* This child1 process */
    {
        sleep(1);
        printf("Child process\n");
        exit(0);
    }
    /* Wait for child process to exit */
    pid = wait(&status);
    printf("Child process status is %d its pid was %d\n", status, pid);
    printf("Parent process, my pid is %d\n",getpid());
    return 0;
}
