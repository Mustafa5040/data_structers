#include "CircularQueue.h" // The public interface
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Creating queue...\n");
    CircularQueue *q = createCircularQueue(5);

    int a = 10, b = 20, c = 30;

    printf("Enqueuing 10 (int)\n");
    enqueueCircularQueue(q, &a, TYPE_INT);
    
    printf("Enqueuing 20 (int)\n");
    enqueueCircularQueue(q, &b, TYPE_INT);

    Type t;
    int *val = (int *)frontCircularQueue(q, &t);
    printf("Front item is: %d, type: %d\n", *val, t);

    val = (int *)dequeueCircularQueue(q, &t);
    printf("Dequeued item is: %d, type: %d\n", *val, t);

    val = (int *)dequeueCircularQueue(q, &t);
    printf("Dequeued item is: %d, type: %d\n", *val, t);

    if (isCircularQueueEmpty(q))
    {
        printf("Queue is now empty.\n");
    }
    return 0;
}