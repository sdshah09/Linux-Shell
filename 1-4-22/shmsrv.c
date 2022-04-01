#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void togglecase(char *buf,int cnt);
    union semun {
       int val;    /* Value for SETVAL */
       struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       unsigned short  *array;  /* Array for GETALL, SETALL */
       struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

union semun sem_union;
int main(){
    int semid,shmid;
    char *pshm;
    struct sembuf smop;

    semid = semget(MY_KEY,1,0660|IPC_CREAT);
    if(semid<0){
        printf("could not create semaphore\n");
        return 1;
    }
    else{
        printf("opended a semaphore id: %d/n",semid);
    }

    //!set initial token count of both semaphore to zeros
    semctl(semid,0,SETVAL,0); //! 0 is the only first semaphore

    //todo: create a shared memory segment
    shmid = shmget(MY_KEY,SHM_SIZE,0660|IPC_CREAT);
    if(shmid<0){
        printf("could not create shared segment\n");
        return 2;
    }

    pshm = shmat(shmid,NULL,0);
    if(!pshm){
        printf("could not attach sharede emory segment\n");
        return 3;
    }

    while(1){   //todo: server initiated and waiting for the client connection 
                //todo: until client will connect server will wait

        //todo: wait for a token from semapphore 0
        smop.sem_num=0;
        smop.sem_op=-1;
        smop.sem_flg=0;

        semop(semid,&smop,1);

        //*Process the message available in shared memory
        //! critical section that is protected
        printf("Got the semaphore\n");
        strcpy(pshm+256,pshm);
        togglecase(pshm+256,strlen(pshm+256));
        printf("Processed the request message and placed response\n");
        smop.sem_num =1;
        smop.sem_op = 1;
        smop.sem_flg = 0;

        semop(semid,&smop,1);
    }
}

void togglecase(char *buf,int cnt){
    int k;
    for(k=0;k<cnt;k++){
        if((buf[k]>='A') && (buf[k]<='Z')){
            buf[k]+=0x20;
        }
        else if((buf[k]>='a') && (buf[k]<='z')){
            buf[k] -= 0x20;
        }
    }
}

