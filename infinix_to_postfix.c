#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int postfix_calculator(char *str, size_t length);
char *infinix_to_postfix(char *infinix_exp, size_t length);
int main()
{
    // char str[] = "595*+";
    // printf("What is %s? The answer is %d\n", str, postfix_calculator(str, strlen(str)));
    char *infinix_exp = "3 - (6 + 2 * 7) / 5";
    char *str = infinix_to_postfix(infinix_exp, strlen(infinix_exp));
    int answer =  postfix_calculator(str, strlen(str));

    printf("answer: %d",answer);

}

int postfix_calculator(char *str, size_t length)
{ // 234+*

    ArrayStack *stack = createArrayStack(length);

    for (int i = 0; i < length; i++)
    {
        if(*(str + i) == ' '){
            continue;
        }
        if (*(str + i) >= '0' && *(str + i) <= '9')
        {
            int *str_int = malloc(sizeof(int));
            *str_int = *(str + i) - '0';
            pushArrayStack(stack, TYPE_INT, str_int);
        }
        else if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '*' || *(str + i) == '/')
        {

            int operand2 = *(int *)popArrayStack(stack, NULL);
            int operand1 = *(int *)popArrayStack(stack, NULL);

            int *result = malloc(sizeof(int));
            switch (*(str + i))
            {
            case '+':
            {
                *result = operand1 + operand2;
                break;
            }
            case '-':
            {
                *result = operand1 - operand2;
                break;
            }
            case '*':
            {
                *result = operand1 * operand2;
                break;
            }
            case '/':
            {
                if (operand2 == 0)
                {
                    free(result);
                    return -1;
                }
                *result = (int)(operand1 / operand2);
                break;
            }
            default:
            {
                return -1;
            }
            }
            pushArrayStack(stack, TYPE_INT, result);
        }
    }
    return *(int *)popArrayStack(stack, NULL);
}

int precedence(char op)
{

    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '/' || op == '*')
    {
        return 2;
    }
    return 0;
}
char *infinix_to_postfix(char *infinix_exp, size_t length)
{
    ArrayStack *stack = createArrayStack(length);
    char *output_str = malloc(length + 1);
    char *p = output_str;
    *p = '\0';
    for (int i = 0; i < length; i++)
    {
        char *ch = (infinix_exp + i);

        // if operand(number)
        if (*ch >= '0' && *ch <= '9')
        {
            p += sprintf(p, "%c ", *ch);
        }

        else if (*ch == '(')
        {
            pushArrayStack(stack, TYPE_CHAR, (void *)ch);
        }

        else if (*ch == ')')
        {
            printf("INSIDE %c", *(char *)peekArrayStack(stack, NULL));
            if (!isArrayStackEmpty(stack))
            {
                while (*(char *)peekArrayStack(stack, NULL) != '(')
                {
                    p += sprintf(p, "%c ", *(char *)(popArrayStack(stack, NULL)));
                    if (isArrayStackEmpty(stack))
                    {
                        break;
                    }
                }
            }
            popArrayStack(stack, NULL); // (
        }
        // if operator
        else if (*ch == '+' || *ch == '-' || *ch == '*' || *ch == '/')
        {
            while (!isArrayStackEmpty(stack) && *(char *)peekArrayStack(stack, NULL) != '(' && precedence(*(char *)peekArrayStack(stack, NULL)) >= precedence(*ch))
            {
                char *op = (char *)popArrayStack(stack, NULL);
                p += sprintf(p, "%c ", *op);
            }

            pushArrayStack(stack, TYPE_CHAR, ch);
        }
    }
    while (!isArrayStackEmpty(stack))
    {
        p += sprintf(p, "%c ", *(char *)popArrayStack(stack, NULL));
    }

    printf("Infinix: %s\nPostfix: %s\n", infinix_exp, output_str);
    return output_str;
}