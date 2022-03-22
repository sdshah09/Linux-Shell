#include<stdio.h> 
#include<stdlib.h>
// extern int EF_PROTECT_BELOW; // todo : to protect lower boundary.

void buggy(){
    int *ptr;
    int i;
    ptr = (int *)malloc(sizeof(int)*5);

    for(i=0;i<3;i++){
        *ptr = 100;
        printf("value at  ptr int ptr = %d\n",(*ptr));
        ptr--;
    }
}

int main(){
    buggy();
    return 0;
}