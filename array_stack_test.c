#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

//compile with: gcc array_stack_test.c array_stack.c -o stack
int main() {
    ArrayStack* my_stack = createArrayStack(10);
    
    if (isArrayStackEmpty(my_stack)) {
        printf("Created stack successfully and currently is empty..\n");
    }

    int a = 42;
    pushArrayStack(my_stack, TYPE_INT, &a);
    
    printf("Stack'e bir eleman eklendi.\n");

    Type type;
    void* out_type = popArrayStack(my_stack, &type);
    
    if (out_type == TYPE_INT) {
        int val = *(int*)out_type;
        printf("The pop value: %d\n", val);
    }
    
    return 0;
}