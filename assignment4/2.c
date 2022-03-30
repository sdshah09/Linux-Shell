#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

pthread_t tid;
struct my_Sd{
    char sm[10];
};

void *func(void *arg){
    struct my_Sd *d;
    d = (struct my_Sd *)arg;
    printf("thread created\n");
    printf("structure information: %s\n",d->sm);
}

int main(){
    struct my_Sd str;
    strcpy(str.sm,"shaswat\n");
    pthread_create(&tid,NULL,func,(void *)&str);
    pthread_exit(NULL);
}