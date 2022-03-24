#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct my_thread{
    int thread_id;
    char msg[100];
};

void *printhello(void *threadobj){
    pthread_t thread_ID;
    struct my_thread *t1;
    t1=(struct my_thread *) threadobj;
    thread_ID = pthread_self();
    printf("\nThread ID : %u",thread_ID);
    printf("\n %d Thread Message: %s\n",t1->thread_id,t1->msg);
}

int main(){
    pthread_t t1,t2,t3,thread_ID;
    int rc;
    struct my_thread t4,t5,t6;
    t6.thread_id=6;
    strcpy(t6.msg,"Hii\n");
    t4.thread_id=4;
    strcpy(t4.msg,"Hello\n");
    t5.thread_id=5;
    strcpy(t5.msg,"Hola\n");

    thread_ID = pthread_self();
    printf("\n MAIN THREAD ID: %u",thread_ID);

    pthread_create(&t3,NULL,printhello,(void*)&t6);
    pthread_create(&t2,NULL,printhello,(void*)&t4);
    pthread_create(&t1,NULL,printhello,(void*)&t5);

    printf("Exit\n");
    pthread_exit(NULL);
}