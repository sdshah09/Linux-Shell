#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int shared_var = 5; // shared variable
sem_t sem; // create a semaphore
void *thread_inc(void *arg){
    sem_wait(&sem);  // take semaphore
    shared_var++;   // critical section
    sem_post(&sem); // release semaphore
    printf("after increment = %d\n",shared_var);
}

void *thread_dec(void *arg){
    sem_wait(&sem);
    shared_var--;
    sem_post(&sem);
    printf("after decrement = %d\n",shared_var);
}

int main(){

    pthread_t t1,t2;

    sem_init(&sem,.0,1);    //initialize semaphore

    pthread_create(&t1,NULL,thread_inc,NULL);
    pthread_create(&t2,NULL,thread_dec,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    printf("shared variable = %d\n",shared_var);
    return 0;
}