#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>


    void cb1(){
        printf("callback function 1 called\n");
    }

    void cb2(){
        printf("callback function 2 called\n");
    }

    void cb3(){
        printf("callback function 3 called\n");
    }

int main(){
    printf("registering callback1\n");
    atexit(cb1);
    printf("registering callback2\n");
    atexit(cb2);
    printf("registering callback3\n");
    atexit(cb3);

    exit(0);
    //_exit(0); is not calling the functions which are previously rgistered with atexit function.
}   // _ IS A MODIFIER o