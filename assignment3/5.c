// 5.Write a program that implements threads synchronization using mutex techniques.we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>


int s = 7; 
pthread_mutex_t mut; 

void * thread1_inc(void *arg){
    pthread_mutex_lock(&mut); 
    s++; 
    pthread_mutex_unlock(&mut); 
    printf("after increment=%d\n", s);
}

void * thread2_dec(void *arg){
    pthread_mutex_lock(&mut); 
    s--; 
    pthread_mutex_unlock(&mut); 
    printf("after decrement=%d\n", s);
}

int main(){
    pthread_t tid, tid1;

    pthread_mutex_init(&mut, NULL); 

    pthread_create(&tid, NULL, thread1_inc, NULL);
    pthread_create(&tid1, NULL, thread2_dec, NULL);

    pthread_join(tid, NULL); 
    pthread_join(tid1, NULL); 
    printf("shared variable: %d\n", s);
    return 0;
}