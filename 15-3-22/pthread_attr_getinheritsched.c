#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

void* proc(void* param)
{
    sleep(3);
    return 0;
}

int main(int argc, char *argv[]){
    pthread_attr_t attr;
    pthread_t id;
    int err, info;

    pthread_attr_init(&attr);
    //pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
    pthread_attr_getinheritsched(&attr,&info);

    switch(info){

        case PTHREAD_INHERIT_SCHED:
            printf("\nSCHED\n");
            break;
    

        case PTHREAD_EXPLICIT_SCHED:
            printf("\nEXPLICIT\n");
            break;
}

pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
    pthread_attr_getinheritsched(&attr,&info);

    switch(info){

        case PTHREAD_INHERIT_SCHED:
            printf("\nSCHED\n");
            break;
    

        case PTHREAD_EXPLICIT_SCHED:
            printf("\nEXPLICIT\n");
            break;
}
pthread_create(&id,&attr,proc,NULL);
return 0;
}