#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_backwards(char *str, size_t size);
// compile with gcc display_backwards.c ArrayStack.c  -o display_backwards
int main()
{

    char *str = "MUSTAFA DURSUN";
    display_backwards(str, strlen(str));
}

void display_backwards(char *str, size_t size)
{

    ArrayStack *arr_stack = createArrayStack(size - 1); // 14

    for (int i = 0; i < size - 1; i++)
    {
        putchar(*(int*)(str + i));
        //printf("\n SON\n");
        pushArrayStack(arr_stack, TYPE_CHAR, (void *)(str + i));
    }
    putchar((int)('\n'));

    char *output_str = malloc(size);
    char *output_ptr = output_str;
    *output_ptr = '\0';
    char *curr_char = (char *) popArrayStack(arr_stack, NULL);

    while (curr_char != NULL)
    {
        *output_ptr = *curr_char;
        output_ptr++;
        curr_char = (char *)popArrayStack(arr_stack, NULL);
    }
    *output_ptr = '\0';
    printf("%s\n",output_str);
}