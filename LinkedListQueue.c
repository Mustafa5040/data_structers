#include "LinkedListQueue.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListQueue
{
    LinkedList *internal_linked_list;
} LinkedListQueue;


LinkedListQueue *createLinkedListQueue()
{

    LinkedListQueue *linked_list_queue = malloc(sizeof(LinkedListQueue));
    LinkedList *linked_list = createLinkedList();
    linked_list_queue->internal_linked_list = linked_list;
    return linked_list_queue;
}

Node *frontLinkedListQueue(LinkedListQueue *linked_list_queue)
{

    return first(linked_list_queue->internal_linked_list);
}

void *dequeue(LinkedListQueue *linked_list_queue, Type *type)
{

    if (linked_list_queue == NULL)
    {
        if (type != NULL)
            *type = -1;
        return NULL;
    }
    if(linked_list_queue->internal_linked_list == NULL)
    if(first(linked_list_queue->internal_linked_list == NULL)){
        if (type != NULL)
            *type = -1;
        return NULL;
    }
    void *data = getNodeData(first(linked_list_queue->internal_linked_list), type);
    removeFirstNode(linked_list_queue->internal_linked_list);
    return data;
}

void enqueue(LinkedListQueue *linked_list_queue, void *data, Type type)
{
    if (linked_list_queue == NULL)
    {
        return;
    }
    if (linked_list_queue->internal_linked_list == NULL)
    {
        return;
    }
    fastInsertAtTail(linked_list_queue->internal_linked_list,type,data);
}
