#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

void *printHello(void *threadid){
    printf("\n Hello World\n");
while(1);
}

int main(){
    pthread_t thread;
    int rc,t=0;
    printf("Creating thread\n");
    rc = pthread_create(&thread,NULL,printHello,NULL);
    printf("\n Thread ID: %u",thread);
    sleep(6);
    t = pthread_cancel(thread);
    if(t==0){
        printf("\n cancel thread\n");

    }
    printf("\n Thread ID : %u\n",thread);
}