#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

int main(){
    int ret,i,cnt=0;
    errno=0;
    ret = nice(9);
    if(ret==-1&&errno!=0){
        perror("nice");
    }
    else{
        printf("nice value is %d\n",ret);
    }
    while(1){
        printf("Process with nice value %d count = %d\n",ret,cnt);
        for(i=0;i<1000000;i++){
            cnt++;
        }
    }
    return 0;
}