#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//compile with gcc undo_sequence.c ArrayStack.c  -o undo_sequence
int main(){
    //"Helo//llo V/Word/ld" + \0
    char *input_str = malloc(20);
    char *p = input_str;
    ArrayStack *arr_stack = createArrayStack(20);
    char del = '*';
    *p = '\0';
    p += snprintf(input_str, 20,"Helo**llo V*Word*ld");

    for(int i = 0; i < 19; i++){
        
        if( *(input_str + i) != del ){

            pushArrayStack(arr_stack,TYPE_CHAR, (input_str + i) );
        }
        else{

            popArrayStack(arr_stack, NULL);
        }
    }

    char *output_str = malloc(12);
    char *output_ptr = output_str + 10;
    *(output_ptr + 1) = '\0';
    char* curr_char = popArrayStack(arr_stack,NULL);

    while(curr_char != NULL){
        
        *(output_ptr--) = *curr_char;
        curr_char = popArrayStack(arr_stack,NULL); 
    }

    printf("%s\n",output_str);
}