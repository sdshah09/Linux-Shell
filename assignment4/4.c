#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

void* proc(void* param){
    sleep(1);
    return 0;
}

int main(){
    pthread_attr_t Attr;
    pthread_t id;
    
   
    void * my_stack;
    struct sched_param p;

    pthread_attr_init(&Attr);
    int *sc;

    pthread_attr_getschedpolicy(&Attr,&sc);
    pthread_attr_getschedparam(&Attr,&p);
    printf("Scheduling= %d\tPriority = %d\n",sc,p.sched_priority);

     sc=1;
    p.sched_priority=18;

    pthread_create(&id,&Attr,proc,NULL);

    pthread_attr_setschedpolicy(&Attr,sc);
    pthread_attr_setschedparam(&Attr,&p);

    pthread_attr_getschedparam(&Attr,&p);
    pthread_attr_getschedpolicy(&Attr,&sc);
    printf("Scheduling = %ld\tPriority = %ld\n",sc,p.sched_priority);
}