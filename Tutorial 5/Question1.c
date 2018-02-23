#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milli_secs)
{
    clock_t start_time = clock();
    while (clock() < start_time + (milli_secs * 1000))
        ;
}

void* goodbye(void* foo)
{
    int r = rand() % 8; /* Get random number b/w 0 and 7 */
    delay(r * 1000);
    printf("Goodbye\n");
    pthread_exit(NULL);
}

void* hello_world(void* foo)
{
    int r = rand() % 8;
    delay(r * 1000);
    printf("Hello world\n");
    pthread_exit(NULL);
}

int main()
{
    srand(time(NULL));  // should only be called once
    pthread_t thread1, thread2;
    int t1_status, t2_status;
    t1_status = pthread_create(&thread1, NULL, hello_world, NULL);
    if (t1_status) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", t1_status);
        exit(1);
    }
    t2_status = pthread_create(&thread2, NULL, goodbye, NULL);
    if (t2_status) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", t2_status);
        exit(1);
    }

    /* Wait for the threads to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
