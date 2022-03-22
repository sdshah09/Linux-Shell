#include<stdio.h>
#include<stdlib.h>
//! code to dereference a null pointer
int main(){
    int *i;
    float *f;
    char *c;

    i=NULL;
    f=NULL;
    c=NULL;
    printf("value of i: %d\n",*i);
    return 0;
}