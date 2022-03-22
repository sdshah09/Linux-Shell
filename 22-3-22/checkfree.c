#include<stdio.h> 
#include<stdlib.h>
// extern int EF_PROTECT_BELOW; // todo : to protect lower boundary.

void buggy(){
    int *ptr;
    //int i;
    ptr = (int *)malloc(sizeof(int));

        *ptr = 100;
        printf("value at  ptr int ptr = %d\n",(*ptr));
        free(ptr);
        *ptr=99;
    
}

int main(){
    buggy();
    return 0;
}