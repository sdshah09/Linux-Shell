#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>
#define NUM 3
int i = 0;
void *myfun(void *null){
    i++;
    int r = 0; //result
    r = r + i*1000;
    printf("result = %d\n",r);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t th[NUM];
    pthread_attr_t attr;
    int rc,t,status,detach_state;

    pthread_attr_init(&attr);

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    for(t=0;t<NUM;t++){
        printf("Creating thread %d\n",t);
        pthread_create(&th[t],&attr,myfun,NULL);
    }

    pthread_attr_getdetachstate(&attr,&detach_state);
    printf("\n Detach state: %d\n",(int *)detach_state);

    printf("\n Exiting from main thread\n");
    pthread_exit(NULL);


}