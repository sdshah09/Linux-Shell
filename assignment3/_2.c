#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *hello(void *arg){
    printf("Linux Kernel Programming");
    return NULL;
}

int main(){
    pthread_t t;
    int r,s;
     printf("\n Thread id: %lu\n",t);
    r = pthread_create(&t,NULL,hello,(void *)1);
   
    sleep(1);
    s = pthread_cancel(t);
    
    if(s){
        printf("\n cancel thread\n");

    }
    printf("\n Thread id : %lu\n",t);
    pthread_exit(t);
    return 0;
}