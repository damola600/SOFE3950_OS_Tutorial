#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 10
double total_grade = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* class_total(void* grade_ptr)
{
    double grade      = *((double*)grade_ptr);
    pthread_mutex_lock(&mutex);
    total_grade += grade;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    double grade[NUM];
    pthread_t threads[NUM];
    int thread_status;
    printf("Enter the grades of %d students, return after entering each grade..\n",NUM);
    for (int i = 0; i < NUM; ++i) {
        scanf("%lf", &grade[i]);
    }
    /* Create and call the bellcurve function 5 times */
    for (int i = 0; i < NUM; ++i) {
        thread_status = pthread_create(&threads[i], NULL, class_total, (void*)&grade[i]);
        if (thread_status) {
            fprintf(stderr, "Error - can't create thread %d return code: %d\n", i, thread_status);
            exit(1);
        }
    }
    /* Wait for the threads to finish */
    for (int i = 0; i < NUM; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("The total grade of all the students is %.2f\n",total_grade);
    return 0;
}
