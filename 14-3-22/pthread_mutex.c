#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>


int shared_var = 5; // shared variable
pthread_mutex_t my_mutex;
void *thread_inc(void *arg){
    pthread_mutex_lock(&my_mutex);  
    shared_var++;   // critical section
    pthread_mutex_unlock(&my_mutex);
    printf("after increment = %d\n",shared_var);
}

void *thread_dec(void *arg){
    pthread_mutex_lock(&my_mutex);
    shared_var--;
    pthread_mutex_unlock(&my_mutex);
    printf("after decrement = %d\n",shared_var);
}

int main(){

    pthread_t t1,t2;

    pthread_mutex_init(&my_mutex,NULL);    //initialize mutex

    pthread_create(&t1,NULL,thread_inc,NULL);
    pthread_create(&t2,NULL,thread_dec,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    printf("shared variable = %d\n",shared_var);
    return 0;
}