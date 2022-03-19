#include<stdio.h>
#include<stdlib.h>

void buggy(){
    int *ptr;
    int i;
    ptr = (int *)malloc(sizeof(int)*5);
    printf("MALLOC checking : Addr = %08x and Size =%d\n",ptr,sizeof(int)*5);
    for(i=0;i<=10;i++){
        *ptr = 100;
        printf("value at ptr = %d\n",(*ptr));
        ptr++;
    }
}

int main(){
    buggy();
    return 0;
}