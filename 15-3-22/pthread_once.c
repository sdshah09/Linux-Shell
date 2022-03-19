#include<pthread.h>
#include<stdio.h>

//pthread_once()->Establishes a function that will be executed 
// only once in a given process. 
// You may have each thread call the function, 
// but only the first call causes the function to run. 
// This is true even if called simultaneously by multiple threads.


pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit(){
    printf("\nI am in init fun\n");
}

void *mythread(void *i){
    printf("\nI am in my thread: %d\n",(int *)i);
    pthread_once(&once,(void *)myinit);
    printf("\nExit from my thread: %d\n",(int *)i);
}

int main(){
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,mythread,(void *)1);
    pthread_create(&t2,NULL,mythread,(void *)2);
    pthread_create(&t3,NULL,mythread,(void *)3);
    printf("Exit from Main thread\n");
    pthread_exit(NULL);
    }