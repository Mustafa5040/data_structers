#include "Queue.h"
#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrome(char *str, size_t length)
{
    ArrayStack *stack = createArrayStack(strlen(str));
    Queue *queue = createQueue(str1en(str));
    for (int i = 0; i < length; i++)
    {
        enqueue(queue, (void *)(str + i), TYPE_CHAR);
        pushArrayStack(stack, TYPE_CHAR, (void *)(str + i));
    }

    while (!isQueueEmpty(queue))
    {
        if (*(char *)front(queue, NULL) != *(char *)peekArrayStack(stack, NULL) )
        {
            return 0;
        }
        dequeue(queue,NULL);
        popArrayStack(stack,NULL);
    }
    return 1;
}