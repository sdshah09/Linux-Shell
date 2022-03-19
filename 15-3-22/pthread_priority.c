// This code is to give priority to any thread you want.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

void *my(void *i){
    printf("\n I am in %d thread \n",(int *)i);
}

int main(){
    pthread_t tid;
    struct sched_param param;
    int priority,policy,ret; // scheduling paramters of target thread
    ret = pthread_getschedparam(pthread_self(),&policy,&param);
    if(ret!=0){
        perror("getschedparam");

    }
    printf("\n----------------Main thread-----------\n Policy : %d \t Priority: %d\n"
    ,policy,param.sched_priority);

    policy = SCHED_FIFO;
    param.sched_priority = 3;
    ret = pthread_setschedparam(pthread_self(),policy,&param);
    if(ret!=0){
        perror('getschedparam');
    }

    ret = pthread_getschedparam(pthread_self(),&policy,&param);
    if(ret!=0){
        perror("getschedparam");
    }
    
    printf("\n----------------Main thread-----------\n Policy : %d \t Priority: %d\n"
    ,policy,param.sched_priority);


}