#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> /* For sleep() */

void read_file(const char* filename)
{
    sleep(1);
    int c;
    FILE* file = fopen(filename, "r");
    if (file) {
        while ((c = getc(file)) != EOF) putchar(c);
        fclose(file);
    }
    exit(0);
}

int main()
{
    int pid;
    int status        = 0;
    const char* file1 = "child1.txt";
     const char* file2 = "child2.txt";
     FILE* child1      = fopen(file1, "w");
     FILE* child2      = fopen(file2, "w");
     if (child1 == NULL || child2 == NULL) {
	 printf("File for writing could not be opened!!.. exiting...");
	 exit(EXIT_FAILURE);
     }
     fprintf(child1, "Child 1\n");
     fprintf(child2, "Child 2\n");
     fclose(child2);
     fclose(child1);
     if (fork() == 0) /* This child1 process */
        read_file(file1);
    else {
        if (fork() == 0) /* This is child2 */
            read_file(file2);
    }
    /* Wait for child process to exit */
    while ((pid = wait(&status)) > 0)
        ;
    return 0;
}
