#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

static void* threadfunc(void *arg){
    char *s = (char *)arg;
    printf("%s\n",s);
    return 0;
}

int main(int argc,char *argv[]){
    pthread_t t1;
    void *res;
    int s;

    s =pthread_create(&t1,NULL,threadfunc,"Hello World");

    printf("Messages from main()\n");;
    sleep(3);
    exit(0); 
}