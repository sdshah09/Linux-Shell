#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

struct my_thread{
    int tid;
    char mesg[100];
};

void *printhello(void *threadobj){
    pthread_t tId;
    struct my_thread *t1;
    t1 = (struct my_thread *)threadobj;
    tId = pthread_self();
    printf("\n thread id: %u",tId);
    printf("\n %d thread message : %s\n",t1->tid,t1->mesg);
}

int main(){
    pthread_t th1,th2,th3,tId;
    int rc;
    struct my_thread t1,t2,t3;
    t3.tid=3;
    strcpy(t3.mesg,"I am third thread\n");
    t1.tid=1;
    strcpy(t1.mesg,"I am first thread\n");
    t2.tid=2;
    strcpy(t3.mesg,"I am second thread\n");

    tId = pthread_self();
    printf("\n Main thread id: %u",tId);

    pthread_create(&th3,NULL,printhello,(void *)&t3);

    printf("\n Exit fromm main thread\n");
    pthread_exit(NULL);
}