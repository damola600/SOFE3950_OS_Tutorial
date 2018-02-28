#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* bellcurve(void* grade_ptr)
{
    double grade      = *((double*)grade_ptr);
    double bell_grade = grade * 1.5;
    pthread_mutex_lock(&mutex);
    printf("The grade is %f\n", grade);
    printf("The bellcurved grade is %f\n", bell_grade);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    double grade[5];
    pthread_t threads[5];
    int thread_status;
    printf("Enter the grades of 5 students, return after entering each grade..\n");
    for (int i = 0; i < 5; ++i) {
        scanf("%lf", &grade[i]);
    }
    /* Create and call the bellcurve function 5 times */
    for (int i = 0; i < 5; ++i) {
        thread_status = pthread_create(&threads[i], NULL, bellcurve, (void*)&grade[i]);
        if (thread_status) {
            fprintf(stderr, "Error - can't create thread %d return code: %d\n", i, thread_status);
            exit(1);
        }
    }
    /* Wait for the threads to finish */
    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
