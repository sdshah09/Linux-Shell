#include<stdio.h>
#include<stdlib.h>

void buggy(int *p){
    p[0]=10;
    //free(p); //*free ptr
}

int main(){
    int *ptr;
    ptr = (int *)malloc(4); //*creating 4 bytes
    buggy(ptr); //* passinfg addr of 4 bytes through a ptr
    free(ptr);  // * double free i.e. trying to free a ptr taht is already freed
}