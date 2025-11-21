#include <stdio.h>

int fact(int num);

int main(){
    int num = 5;
    printf("factorial of %d is %d\n",num,fact(num));
}

int fact(int num){

    if(num < 0){
        return -1;
    }
    if(num == 0){
        return 1;
    }
    return num * fact(num-1);
}