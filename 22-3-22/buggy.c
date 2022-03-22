#include<stdio.h> // todo it is a upper memory boundary violation.
#include<stdlib.h>

void buggy(){
    int *ptr;
    int i;
    ptr = (int *)malloc(sizeof(int)*5);

    for(i=0;i<14;i++){
        *ptr = 100;
        printf("value at  ptr int ptr = %d\n",(*ptr));
        ptr++;
    }
}

int main(){
    buggy();
    return 0;
}