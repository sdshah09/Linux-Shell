#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void method(void *arg){

    printf("Thread... Created.... %d\n",(int*)arg);
}

int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,method,100);
    pthread_exit(tid);
    return 0;
}