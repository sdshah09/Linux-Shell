#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *one(){
    printf("only one time\n");
}

void *func(void *argv){
    printf("Thread 1: %d\n",(int *)argv);
    pthread_once(&once,(void *)one);
    printf("Exit: %d\n",(int *)argv);
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func,(void *)9);
    pthread_create(&t2,NULL,func,(void *)99);
    pthread_exit(NULL);
    return 0;
}