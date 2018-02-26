#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 10
double total_grade     = 0;
double total_bellcurve = 0;
pthread_mutex_t mutex  = PTHREAD_MUTEX_INITIALIZER;

void* read_grades(void* grade_ptr)
{
    double* grades = (double*)grade_ptr;
    FILE* input    = fopen("grades.txt", "r");
    if (input == NULL) {
        printf("File grades.txt could not be opened!!.. exiting...");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < NUM; ++i) fscanf(input, "%lf", &grades[i]);
    fclose(input);  // Close the file
    pthread_exit(NULL);
}

void* save_bellcurve(void* grade_ptr)
{
    double grade = *((double*)grade_ptr);
    pthread_mutex_lock(&mutex);
    total_grade += grade;
    total_bellcurve += (grade * 1.5);
    FILE* input    = fopen("bellcurve.txt", "a");
    if (input == NULL) {
        printf("File bellcurve.txt could not be opened!!.. exiting...");
        exit(EXIT_FAILURE);
    }
    fprintf(input, "Bellcurved grade %lf\n", grade*1.5);
    fclose(input);  // Close the file
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    double grades[NUM];
    pthread_t threads[NUM];
    int thread_status;
    /* Read data using a seperate thread */
    pthread_t read_thread;
    printf("Trying to read the grades...\n");
    thread_status = pthread_create(&read_thread, NULL, read_grades, &grades);
    pthread_join(read_thread, NULL);
    /* Create NUM threads to do the calculation */
    for (int i = 0; i < NUM; ++i) {
        thread_status = pthread_create(&threads[i], NULL, save_bellcurve, (void*)&grades[i]);
        if (thread_status) {
            fprintf(stderr, "Error - can't create thread %d return code: %d\n", i, thread_status);
            exit(1);
        }
    }
    /* Wait for the threads to finish */
    for (int i = 0; i < NUM; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("The total grade of all the students is %.2f\n", total_grade);
    printf("The total grade of all the students after bell_curve is %.2f\n", total_bellcurve);
    printf("The average grade of all the students is %.2f\n", total_grade/NUM);
    printf("The average grade of all the students after bell curve is %.2f\n", total_bellcurve/NUM);
    return 0;
}
