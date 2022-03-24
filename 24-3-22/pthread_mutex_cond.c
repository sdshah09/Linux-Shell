#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;

void *foo(void *arg){
    char *str = (char*)arg;
    printf("thread task called by = %s\n",str);
    pthread_mutex_lock(&lock);

    if(done==1){
        printf("waiting on conditon variable cond1\n");
        pthread_cond_wait(&cond1,&lock);
    }

    else{
        //let's signal conditon variable cond1
        printf("signaling condition variable cond1\n ");
        pthread_cond_signal(&cond1);
    }
    //relase lock
    pthread_mutex_unlock(&lock);
    printf("Returning Thread\n");
    return NULL;
}

int main(){
    pthread_t tid1;
    pthread_t tid2;

    //create thread1
    pthread_create(&tid1,NULL,foo,"THDONE");

    //sleep for 1 second so that thread 1 would get a chance to run first
    sleep(1);

    //lets wait on conditon 1
    done=2;
    pthread_create(&tid2,NULL,foo,"THDTWO");
    pthread_join(tid2,NULL);
    return 0;

}