// 4. Write a program where pthread task displays the thread id and also prints the calling process pid.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t tid;

void * t1(void *arg){
    printf("newly created thread is executing\n");
    printf("thread is created, thread ID = %u\n", tid);
    return NULL;
}

int main(){
    int ret = pthread_create(&tid, NULL, t1, NULL);
    int rc, t;

    pthread_t ttid = pthread_self();
    printf("calling process process ID = %u\n", ttid);

    if(ret){
        printf("thread is not created\n");
    } else{
        pthread_join(tid, NULL); 
    }
    return 0;
}