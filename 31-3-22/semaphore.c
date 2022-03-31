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

union semun {
       int val;    /* Value for SETVAL */
       struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       unsigned short  *array;  /* Array for GETALL, SETALL */
       struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

int get_release(void);
int get_semaforce(void);
struct sembuf sem_op;
union semun sem_union;
int sid;
int main(){
    int i;
    sleep(3);

    sid = semget((key_t)10,1,0666|IPC_CREAT);
    printf("\nsemaforce ID: %d\n",sid);

    sem_union.val = 1;
    if(semctl(sid,0,SETVAL,sem_union)<0){
        printf("error\n");
    }

    for(i=0;i<=5;i++){
        get_semaforce();
        printf("\n%d: got the semaforce\n",getpid());
        sleep(1);
        printf("\n%d: release the semaforce\n",getpid());
        get_release();
        sleep(1);
    }

    if(semctl(sid,0,IPC_RMID,sem_union)<0){
        printf("fails to delete the sempahore\n");
    }
    else{
        printf("semaphore deleted\n");
    }
}

    int get_semaforce(void){
        sem_op.sem_num=0;
        sem_op.sem_op=-1;
        sem_op.sem_flg=SEM_UNDO;
        if(semop(sid,&sem_op,1)<0){
            printf("failed\n");
            return -1;
        }
    }

    int get_release(void){
        sem_op.sem_num=0;
        sem_op.sem_op=-1;
        sem_op.sem_flg=SEM_UNDO;

        if(semop(sid,&sem_op,1)<0){
            printf("failed\n");
            return -1;
        }
    }
