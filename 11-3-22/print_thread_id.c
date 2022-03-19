#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid;

void *thr_fn(void *arg){
pid_t pid;
pthread_t tid;
pid = getpid();
tid = pthread_self();
printf(" pid %u tid %u \n",(unsigned int)pid,(unsigned int)tid);
return 0;
}

int main(){
    int err;
    err = pthread_create(&tid,NULL,thr_fn,NULL);
   
    while(1);
    exit(0);
}