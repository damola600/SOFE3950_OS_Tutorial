#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct Student {
    char name[256];
    char id[256];
    double grade;
};

void* bellcurve(void* grade_ptr)
{
    struct Student* current = (struct Student*)grade_ptr;  // correct this
    double bell_grade       = current->grade * 1.5;
    pthread_mutex_lock(&mutex);
    printf("Name of the student is is %s\n", current->name);
    printf("ID of the student is is %s\n", current->id);
    printf("The bellcurved grade is %f\n\n", bell_grade);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    struct Student students[NUM];
    pthread_t threads[NUM];
    int thread_status;
    printf("Enter the names,ids and grade of 5 students, return after each student..\n");
    for (int i = 0; i < NUM; ++i) {
        printf("Student %d--\n", i + 1);
        printf("Enter student's name: ");
        scanf("%s[^\n]", &students[i].name);
        printf("Enter student's id: ");
        scanf("%s[^\n]", &students[i].id);
        printf("Enter student's grade: ");
        scanf("%lf", &students[i].grade);
	printf("\n");
    }
    /* Create and call the bellcurve function NUM times */
    for (int i = 0; i < NUM; ++i) {
        thread_status = pthread_create(&threads[i], NULL, bellcurve, (void*)&students[i]);
        if (thread_status) {
            fprintf(stderr, "Error - can't create thread %d return code: %d\n", i, thread_status);
            exit(1);
        }
    }
    /* Wait for the threads to finish */
    for (int i = 0; i < NUM; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
