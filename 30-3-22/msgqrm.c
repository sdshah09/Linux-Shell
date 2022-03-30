#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/msg.h>

#define KEY 8979

int main(){
    int qid;
    struct msqid_ds buf;
    qid = msgget(49,IPC_CREAT|0644);
    printf("qid = %d\n",qid);
    msgctl(qid,IPC_RMID,NULL);
}
