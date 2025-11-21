#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dec_to_bin(int dec);

int main(int argc, char **argv)
{
    int default_value = 233;
    int curr_dec;
    printf("argc: %d\n",argc);
    if (argc < 2)
    {
        curr_dec = default_value;
    }
    else
    {
        curr_dec = atoi(argv[1]);
    }

    char *bin_str = dec_to_bin(curr_dec);
    printf("---------------\ndec: %d\nbin: %s\n-------------", curr_dec, bin_str);
}

char *dec_to_bin(int dec)
{

    ArrayStack *arr_stack = createArrayStack(32);
    int count = 0;

    if (dec == 0)
    {
        int *send = malloc(sizeof(int));
        *send = 0;
        pushArrayStack(arr_stack, TYPE_INT, (void *)send);
        count++;
    }
    while (dec > 0)
    {
        int *reminder = malloc(sizeof(int));
        *reminder = dec % 2;
        pushArrayStack(arr_stack, TYPE_INT, (void *)(reminder));
        dec = (int)(dec / 2);
        count++;
    }
    char *str = malloc(count + 1);
    char *p = str;
    *p = '\0';
    int *curr_int = (int *)popArrayStack(arr_stack, NULL);

    while (curr_int != NULL)
    {
        p += sprintf(p, "%d", *curr_int);
        curr_int = (int *)popArrayStack(arr_stack, NULL);
    }
    return str;
}