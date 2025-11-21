#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    void **internal_array;
    Type *types;
    int frontCircularQueue;
    int back;
    int capacity;
    int count;
} CircularQueue;

CircularQueue *createCircularQueue(int capacity)
{

    CircularQueue *queue = malloc(sizeof(CircularQueue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->internal_array = malloc(sizeof(void *) * capacity);
    if (queue->internal_array == NULL)
    {
        free(queue);
        return NULL;
    }
    queue->types = malloc(sizeof(Type) * capacity);
    if (queue->types == NULL)
    {
        free(queue->internal_array);
        free(queue);
        return NULL;
    }
    queue->frontCircularQueue = 0; // queue'nun en eskisi arrayin en başı
    queue->back = 0;  // queue'nin en yenisinin sonrası, sonraki avaliable slot
    queue->capacity = capacity;
    queue->count = 0;

    return queue;
}

void *frontCircularQueue(CircularQueue *queue, Type *type)
{
    if (queue ==    NULL)
    {
        if(type != NULL){
            *type = -1;
        }
        return NULL;
    }
    if (isCircularQueueEmpty(queue))
        return NULL;

    if (type != NULL)
    {
        *type = queue->types[queue->frontCircularQueue];
    }
    void *data = *(queue->internal_array + queue->frontCircularQueue);
    return data;
    // queue->frontCircularQueue = (queue->frontCircularQueue + 1 % (queue->capacity - 1))
}

void *dequeueCircularQueue(CircularQueue *queue, Type *type){

    if (queue == NULL)
    {
        if(type != NULL){
            type = NULL;
        }
        return NULL;
    }
    if (isCircularQueueEmpty(queue))
        return NULL;

    if (type != NULL)
    {
        *type = queue->types[queue->frontCircularQueue];
    }
    void* data = frontCircularQueue(queue,type);
    queue->frontCircularQueue = ((queue->frontCircularQueue + 1) % (queue->capacity));
    queue->count--;
    return data;
}

void enqueueCircularQueue(CircularQueue *queue, void* data, Type type){

    if (queue == NULL)
    {
        return;
    }
    if(queue->internal_array == NULL){
        return;
    }
    if(isCircularQueueFull(queue)){
        return;
    }

    *(queue->internal_array + queue->back) = data;
    *(queue->types + queue->back) = type;
    queue->back = ((queue->back+1) % (queue->capacity));
    queue->count++;
}

int isCircularQueueFull(CircularQueue *queue)
{
    if (queue == NULL)
        return 0;

    if (queue->internal_array == NULL)
        return 0;

    return queue->count == queue->capacity;
}

int isCircularQueueEmpty(CircularQueue *queue)
{
    if (queue == NULL)
        return 1;

    if (queue->internal_array == NULL)
        return 1;
    return queue->count == 0;
}