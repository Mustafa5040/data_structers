#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int len = strlen("Helo**llo V*Word*ld");
    char *input_str = malloc(len + 1);
    sprintf(input_str, "Helo**llo V*Word*ld");
    Queue *queue = createQueue(len);

    for (int i = 0; i < len; i++)
    {
        enqueue(queue, (input_str + i), TYPE_CHAR);
    }

    while(!isQueueEmpty(queue)){
        putchar(*(int *)(dequeue(queue,NULL)));
    }
}