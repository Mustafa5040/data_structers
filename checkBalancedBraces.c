#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkBalancedBraces(char *str, size_t size);
// compile with gcc display_backwards.c ArrayStack.c  -o display_backwards
int main()
{

    char *str = "abc{def}}{ghij{kl}m";
    int size = strlen(str);
    int result = checkBalancedBraces(str, size);
    if (result)
    {
        printf("BALANCED!\n");
    }
    else
    {
        printf("UNBALANCED!\n");
    }
}

int checkBalancedBraces(char *str, size_t size)
{

    ArrayStack *arr_stack = createArrayStack(size - 1);

    for (int i = 0; i < size - 1; i++)
    {
        if (*(str + i) == '{')
        {
            putchar(*(int *)(str + i));
            putchar((int)'\n');
            pushArrayStack(arr_stack, TYPE_CHAR, str + i);
        }
        else if (*(str + i) == '}')
        {
            putchar(*(int *)(str + i));
            putchar((int)'\n');
            if(isArrayStackEmpty(arr_stack) != 1){
                   popArrayStack(arr_stack, NULL);
            }
        }
    }

    return isArrayStackEmpty(arr_stack);
}