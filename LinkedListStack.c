#include "LinkedListStack.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListStack
{
    LinkedList *internal_linked_list;
} LinkedListStack;

LinkedListStack *createLinkedListStack()
{
    LinkedListStack *linked_list_stack = malloc(sizeof(LinkedListStack));
    linked_list_stack->internal_linked_list = createLinkedList();
    return linked_list_stack;
}

int pushLinkedListStack(LinkedListStack *stack, Type type, void *data)
{
    if (stack == NULL)
    {
        return 0;
    }

    insertAtHead(stack->internal_linked_list, type, data);
    return 1;
}

void *popLinkedListStack(LinkedListStack *stack, Type *type)
{
    if (stack == NULL)
    {
        if (type != NULL)
        {
            *type = -1;
        }

        return NULL;
    }
    Node *top = first(stack->internal_linked_list);
    if (top == NULL)
    {
        return NULL;
    }
    void *data = getNodeData(top, type);

    if (data == NULL)
    {
        return NULL;
    }

    removeFirstNode(stack->internal_linked_list);

    return data;
}

int isLinkedListStackEmpty(LinkedListStack *stack)
{

    if (stack == NULL)
    {
        return 1;
    }
    if (stack->internal_linked_list == NULL)
    {
        return 1;
    }
    return isLinkedListEmpty(stack->internal_linked_list);
}
void *peekLinkedListStack(LinkedListStack *stack, Type *type)
{

    if (stack == NULL)
    {
        if (type != NULL)
        {
            *type = -1;
        }

        return NULL;
    }

    Node *top = first(stack->internal_linked_list);
    if (top == NULL)
    {
        return NULL;
    }

    return getNodeData(top, type);
}
void makeLinkedListStackEmpty(LinkedListStack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    if (stack->internal_linked_list == NULL)
    {
        return;
    }

    makeLinkedListEmpty(stack->internal_linked_list);
}

void destroyLinkedListStack(LinkedListStack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    if (stack->internal_linked_list != NULL)
    {
        destroyLinkedList(stack->internal_linked_list);
    }
    free(stack);
}