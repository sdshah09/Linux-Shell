#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int s = 5; 

void *thread_inc(void *arg){
    s++;
    printf("after increment = %d\n",s);
}

void *thread_dec(void *arg){
    s--;
    printf("after decrement = %d\n",s);
}

int main(){

    pthread_t t1,t2;
    printf("shared variable = %d\n",s);
    
    if(s%2==0){
    
    pthread_create(&t1,NULL,thread_inc,NULL);
    pthread_join(t1,NULL);
    }

    else{
         pthread_create(&t2,NULL,thread_dec,NULL);
        pthread_join(t2,NULL);
    }
    
    return 0;
}