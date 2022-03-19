#include<stdio.h>
#include<string.h>

int main(){
    char b1[10];
    char b2[10];
    int ret;

    memcpy(b1,"madam",5);
    memcpy(b2,"mad",5);

    ret = memcmp(b1,b2,5);

    if(ret>0){
        printf("b1 is greater than b2\n");
    }
    else if(ret<0){
        printf("b1 is less than b2\n");
    }
    else{
        printf("both are equal\n");
    }
}