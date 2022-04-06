#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/msg.h>

#define KEY 1000

int main(){
    int qid;
    struct msqid_ds buf;
    qid = msgget(20,IPC_CREAT|0644);
    printf("qid = %d\n",qid);
    msgctl(qid,IPC_STAT,&buf);
    printf("Here are the details of queue\n");
    printf("no of msg's in q %hi\n",buf.msg_qnum);
    printf("max no of bytes in q %hi\n",buf.msg_qbytes);
    msgctl(qid,IPC_RMID,NULL);
    printf("Removed id is %d\n ",qid);
}