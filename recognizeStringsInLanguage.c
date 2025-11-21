#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInLanguage(char *str, size_t size);
// compile with gcc display_backwards.c ArrayStack.c  -o display_backwards
int main()
{

    char *str1 = "abc$cba";
    char *str2 = "abc$abc";
    char *str3 = "a$a";
    char *str4 = "$";
    char *str5 = "a$b";
    char *str6 = "a$";

    char *inputs[] = {str1, str2, str3, str4, str5, str6};
    for (int i = 0; i < (sizeof(inputs) / sizeof(char *)); i++)
    {
        int result = isInLanguage(inputs[i], strlen(inputs[i]));

        if (result)
        {
            printf("%s is in language!\n", inputs[i]);
        }
        else
        {
            printf("%s is NOT in language!\n", inputs[i]);
        }
    }
}

int isInLanguage(char *str, size_t size)
{
    ArrayStack *arr_stack = createArrayStack(size - 1);

    char seperators[] = {'$', '#', '/', '*', '&', '%', '@'};
    int seperator_index = -1;
    for (int i = 0; i < size - 1; i++)
    {

        if (seperator_index == -1)
        {
            // seperator kontrolü
            for (int j = 0; j < sizeof(seperators); j++)
            {
                if (*(str + i) == seperators[j])
                {
                    seperator_index = i;
                    continue;
                }
            }
            if (seperator_index == -1)
            {
                // seperator öncesinde, yani ifadenin sol tarafındayız, stack'e ekliyoruz.
                pushArrayStack(arr_stack, TYPE_CHAR, (void *)(str + i));
                continue;
            }
        }

        // seperator'ın sonrasında, yani ifadenin sağ tarafındayız, sol taraftaki karşılığı ile eşitse pop ediyoruz. değilse zaten direkt bitiyiruz.
        if (*(str + i) == *(str + (2 * seperator_index - i)))
        {
            popArrayStack(arr_stack, NULL);
            continue;
        }

        return 0;
    }

    if (isArrayStackEmpty(arr_stack))
    {
        return 1;
    }
    return 0;
}