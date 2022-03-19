#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

static void* threadfunc(void *arg){
    char *s = (char *)arg;
    printf("%s\n",s);
    sleep(5);
    return (void*) strlen(s);
    return 0;
}

int main(int argc,char *argv[]){
    pthread_t t1;
    void *res;
    int s;
    pthread_create(&t1,NULL,threadfunc,"Hello World");

    printf("Messages from main()\n");

    sleep(3);
    pthread_join(t1,&res);
    printf("Thread returned %ld\n", (long)res);
    exit(0);
}