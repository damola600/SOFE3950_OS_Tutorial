#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 5
int moving_sum[NUM] = {0};
sem_t semaphore;

struct Unit {
    int number;
    int index;
};

void* factorial(void* ptr)
{
    int f                = 1;
    struct Unit* current = (struct Unit*)ptr;
    for (int i = 1; i <= current->number; i++) {
        f = f * i;
    }
    while (moving_sum[current->index - 1] == 0) {
        sem_wait(&semaphore);
        if (moving_sum[current->index - 1] > 0)
            moving_sum[current->index] = moving_sum[current->index - 1] + f;
        sem_post(&semaphore);
    }
    pthread_exit(NULL);
}

int main()
{
    struct Unit entries[NUM];
    pthread_t threads[NUM];
    int thread_status;
    printf("Enter %d integers, return after entering each number..\n", NUM);
    for (int i = 0; i < NUM; ++i) {
        scanf("%d", &entries[i].number);
        entries[i].index = i;
    }
    /* Second 0 means the semaphore is shared between threads */
    /* 	Third argumnet 1 is the value of the semaphore in the beingning */
    if (sem_init(&semaphore, 0, 1)) {
        printf("Could not initialize a semaphores\n");
        return -1;
    }
    /* Create and call the factorial function 5 times */
    for (int i = 0; i < NUM; ++i) {
        thread_status = pthread_create(&threads[i], NULL, factorial, (void*)&entries[i]);
        if (thread_status) {
            fprintf(stderr, "Error - can't create thread %d return code: %d\n", i, thread_status);
            exit(1);
        }
    }
    /* Wait for the threads to finish */
    for (int i = 0; i < NUM; ++i) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaphore);
    /*Print results */
    for (int i = 0; i < NUM; ++i) {
        printf("Value of moving sum is %d at index %d\n", moving_sum[i], i);
    }
    return 0;
}
