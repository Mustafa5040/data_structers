#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    void **internal_array;
    Type *types;
    int front;
    int back;
    int capacity;
} Queue;

Queue *createQueue(int internal_capacity)
{
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->internal_array = malloc(sizeof(void *) * internal_capacity);
    if (queue->internal_array == NULL)
    {
        free(queue);
        return NULL;
    }
    queue->types = malloc(sizeof(Type) * internal_capacity);
    if (queue->types == NULL)
    {
        free(queue->internal_array);
        free(queue);
        return NULL;
    }
    queue->front = 0; // queue'nun en eskisi arrayin en başı
    queue->back = 0;  // queue'nin en yenisinin sonrası, sonraki avaliable slot
    queue->capacity = internal_capacity;

    return queue;
}

void *front(Queue *queue, Type *type)
{
    if (queue == NULL || isQueueEmpty(queue))
    {
        if (type != NULL)
            *type = -1;
        return NULL;
    }

    if (queue->internal_array == NULL)
    {
        if (type != NULL)
            *type = -1;
        return NULL;
    }

    if (type != NULL)
    {
        *type = *(queue->types + queue->front);
    }

    return *(queue->internal_array + queue->front);
}

void *dequeue(Queue *queue, Type *type)
{
    if (queue == NULL || isQueueEmpty(queue))
    {   
        return NULL;
    }

    void *data = front(queue, type);

    if (data != NULL)
    {
        queue->front++;
        return data;
    }
    return NULL;
}

int enqueue(Queue *queue, void *data, Type type)
{
    if (queue == NULL || data == NULL)
        return 0;
    if (queue->internal_array == NULL)
        return 0;

    if (isQueueFull(queue))
    {
        // extend capacity
        return 0;
    }

    *(queue->internal_array + queue->back) = data;
    *(queue->types + queue->back) = type;
    queue->back++;
    return 1;
}

int isQueueEmpty(Queue *queue)
{
    if (queue == NULL)
        return -1;
    return (queue->back == queue->front);
}
int isQueueFull(Queue *queue)
{
    if (queue == NULL)
        return -1;
    return queue->back >= queue->capacity;
}
int sizeQueue(Queue *queue){

    return queue->back - queue->front;

}