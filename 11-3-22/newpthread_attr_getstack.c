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

    pthread_attr_init(&Attr);

    pthread_attr_getstacksize(&Attr,&siz);
    pthread_attr_getstacksize(&Attr,&stk);

    printf("Default: Addr =%08x default Size = %d\n",stk,siz);

    my_stack = (void*)malloc(my_stksize);

    pthread_attr_setstack(&Attr,my_stack,my_stksize);
    pthread_create(&id,&Attr,proc,NULL);

    pthread_attr_getstack(&Attr,&stk,&siz);

    printf("new defined stack: Addr = %08x and Size = %d\n",stk,siz);
}