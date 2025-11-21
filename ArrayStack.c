#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack
{
    void **internal_array;
    Type *types;
    int top;
    int capacity;
} ArrayStack;

ArrayStack *createArrayStack(int capacity)
{
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    if (stack == NULL)
    {
        return NULL;
    }
    stack->internal_array = malloc(sizeof(void *) * capacity);
    stack->types = malloc(sizeof(Type) * capacity);
    if (stack->internal_array == NULL || stack->types == NULL)
    {
        free(stack->internal_array);
        free(stack->types);
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int pushArrayStack(ArrayStack *stack, Type type, void *data)
{
    if (stack == NULL)
    {
        return 0;
    }

    if (stack->top == stack->capacity - 1)
    {

        return 0;
    }
    stack->top++;

    stack->internal_array[stack->top] = data;
    stack->types[stack->top] = type;
    return 1;
}

void *popArrayStack(ArrayStack *stack, Type *type)
{
    if (stack == NULL || stack->top < 0)
    {
        if (type != NULL)
        {

            *type = -1;
        }

        return NULL;
    }

    if (type != NULL)
    {
        *type = stack->types[stack->top]; // IMPORTANT
    }

    void *data = stack->internal_array[stack->top];
    stack->top--;
    return data;
}

int isArrayStackEmpty(ArrayStack *stack)
{

    if (stack == NULL)
    {
        return 1;
    }
    return stack->top == -1;
}
int isArrayStackFull(ArrayStack *stack)
{

    if (stack == NULL)
    {
        return 0;
    }
    return stack->top == stack->capacity - 1;
}
void *peekArrayStack(ArrayStack *stack, Type *type)
{

    if (stack == NULL || stack->top < 0)
    {
        if (type != NULL)
        {

            *type = -1;
        }

        return NULL;
    }

    if (type != NULL)
    {
        *type = stack->types[stack->top];
    }

    return stack->internal_array[stack->top];
}
int makeArrayStackEmpty(ArrayStack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }
    if (stack->internal_array == NULL)
    {
        return 0;
    }

    stack->top = -1;
    return 1;
}

void destroyArrayStack(ArrayStack* stack){

    if(stack == NULL){
        return;
    }
    free(stack->internal_array);
    free(stack->types);
    free(stack);
}