#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void abort_handler(int);

void main(){
    if(signal(SIGABRT,abort_handler) == SIG_ERR){
        fprintf(stderr,"could'nt get signal handler\n");
        exit(1);
    }
    abort();
    exit(0);
}

void abort_handler(int i){
    fprintf(stderr,"Caught SIGABRT, exiting application\n");
    printf("Signal number is: %d\n",i);
    exit(1);
}