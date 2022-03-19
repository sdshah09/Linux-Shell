#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t sp;
volatile int s;

void *spinlockThread(void *i){
    int rc;
    int count =0;

    printf("Entered the thread %d,getting spin lock \n",(int*)i);
    //rc = pthread_spin_lock(&s);
    printf("%d Thread complete\n",(int*)i);
    return NULL;
}

int main(){
    int rc=0;
    pthread_t t1,t2;


    printf("Main,create the spin lock thread\n");
    rc= pthread_create(&t1,NULL,spinlockThread,(int*)1);

    // printf("Main, wait a bit holding the spin lock\n");
    // rc = pthread_spin_unlock(&s);
    // if(rc==0){
    //     printf("\n Mai  Thread Successfully unlocked\n");
    // }
    // else{
    //     printf("\n Main Thread unsuccessfully unlocked\n");
    // }

    // printf("Main, wait for the thread to end\n");
    // rc = pthread_join(t1,NULL);
    pthread_exit(NULL);
    printf("Main completed\n");
    return 0;
}
