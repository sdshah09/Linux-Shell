#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

void* proc(void* param){
    sleep(2);
    return 0;
}

int main(){
    pthread_attr_t Attr;
    pthread_t id;
    void *stk;
    size_t siz;
    int err;
    size_t my_stksize= 0x3000000;
    void * my_stack;
    struct sched_param p;

    pthread_attr_init(&Attr);
    int *sc;
    pthread_attr_getstacksize(&Attr,&siz);
    pthread_attr_getstacksize(&Attr,&stk);
    pthread_attr_getschedpolicy(&Attr,&sc);
    pthread_attr_getschedparam(&Attr,&p);
    printf("Default: Addr =%08x\tdefault Size = %d\tScheduling= %d\tPriority = %d\n",stk,siz,sc,p.sched_priority);

    my_stack = (void*)malloc(my_stksize);
     sc=1;
    p.sched_priority=18;

    pthread_attr_setstack(&Attr,my_stack,my_stksize);
    pthread_create(&id,&Attr,proc,NULL);

   

    pthread_attr_setschedpolicy(&Attr,sc);
    pthread_attr_setschedparam(&Attr,&p);

    pthread_attr_getstack(&Attr,&stk,&siz);

   
    
    pthread_attr_getschedparam(&Attr,&p);
    pthread_attr_getschedpolicy(&Attr,&sc);
    printf("new defined stack: Addr = %08x and Size = %d\tScheduling = %ld\tPriority = %ld\n",stk,siz,sc,p.sched_priority);
}