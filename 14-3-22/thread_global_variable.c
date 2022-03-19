#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int shared_var = 5; // shared variable

void *thread_inc(void *arg){
    shared_var++;
    printf("after increment = %d\n",shared_var);
}

void *thread_dec(void *arg){
    shared_var--;
    printf("after decrement = %d\n",shared_var);
}

int main(){

    pthread_t t1,t2;

    pthread_create(&t1,NULL,thread_inc,NULL);
    pthread_create(&t2,NULL,thread_dec,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    printf("shared variable = %d\n",shared_var);
    return 0;
}