#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Queue;

Queue* enqueue(Queue* queue, int value)
{
    Queue* temp = NULL;
    temp        = (Queue*)malloc(sizeof(Queue));
    if (temp == NULL) {
        exit(-1);  // Malloc failed
        return NULL;
    }
    temp->value = value;
    temp->next  = NULL;
    if (queue == NULL)
        queue = temp;
    else {
        while (queue->next != NULL) queue = queue->next;
        queue->next = temp;
    }
    return temp;
}

Queue* dequeue(Queue* queue)
{
    Queue* temp;
    if (queue == NULL) {
        return NULL;
    } else {
        temp = queue->next;
        free(queue);
        return temp;
    }
}

#endif /* QUEUE_HPP */
