#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

void *process(void *arg){

    pthread_detach(pthread_self());

    printf("sleeping 2 secs\n");

    sleep(2);
    printf("slept 2 secs\n");
}

int main(void){

    pthread_t t1;
    int s =  pthread_create(&t1,NULL,process,NULL);
    if(errno){
        perror("pthread_create: ");
    }
    pthread_exit(NULL);
    return 0;
}