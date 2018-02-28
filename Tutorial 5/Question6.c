#define _XOPEN_SOURCE 600
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 10
int g_sum             = 0; /* The global variable that will be used by every thread */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barrier;

void* report_difference(void* ptr)
{
    int some_number = *((int*)ptr);
    pthread_mutex_lock(&mutex);
    g_sum += some_number;
    printf("The difference is %d\n", g_sum - some_number);
    pthread_mutex_unlock(&mutex);
    pthread_barrier_wait(&barrier);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM];
    int thread_status;
    int random_num[NUM] = {1, 3, 4, 5, 6, 10, 45, 65, 23, 41};
    /* Create NUM threads to do the calculation */
    pthread_barrier_init(&barrier, NULL, NUM);
    for (int i = 0; i < NUM; ++i) {
        thread_status = pthread_create(&threads[i], NULL, report_difference, (void*)&random_num[i]);
        if (thread_status) {
            fprintf(stderr, "Error - can't create thread %d return code: %d\n", i, thread_status);
            exit(1);
        }
    }
    /* Wait for the threads to finish before exciting*/
    for (int i = 0; i < NUM; ++i) {
        pthread_join(threads[i], NULL);
    }
    printf("The final sum is %d\n", g_sum);
    pthread_barrier_destroy(&barrier);
    return 0;
}
