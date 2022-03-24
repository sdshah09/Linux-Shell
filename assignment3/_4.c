#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *hello(void *arg){
    printf("Process id is %d\n",getpid());
    return NULL;
}

int main(){
    pthread_t t;
    int r,s;
    printf("\nThread id: %lu\n",t);
    r = pthread_create(&t,NULL,hello,(void *)1);
    pthread_exit(t);
    
    
}