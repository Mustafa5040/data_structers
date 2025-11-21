#include <stdio.h>
#include <math.h>
#include "Queue.h"

int josephus_math(int num_of_mans)
{
    int N = num_of_mans;
    int a = 0;

    while (num_of_mans > 1)
    {
        num_of_mans = (int)(num_of_mans / 2);
        a++;
    }
    return 2 * (N - pow(2, a)) + 1;
}

int josephus_queue(Queue *mans_queue, int k)
{ // for every k elements

    while (sizeQueue(mans_queue) > 1)
    {
        for (int i = 1; i <= k - 1; i++)
        {
            enqueue(mans_queue, dequeue(mans_queue, NULL), TYPE_INT);
        dequeue(mans_queue, NULL);
        }
    }
    return dequeue(mans_queue, NULL);
}

int main()
{
    printf("%d", josephus_math(13));
}