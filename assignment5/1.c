#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(){
    int *p;
    int id;

    id = shmget(30,200,IPC_CREAT|0644);

    if(id<0){
        perror("shmget");
        return 0;
    }

    printf("id=%d\n",id);
    p=shmat(id,0,0);
    
    printf("Address is %p\n",p);
    return 0;
}