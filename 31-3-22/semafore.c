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

int get_semaphore(void);
int release_semaphore(void);
int sem_id;

union semun {
       int val;    /* Value for SETVAL */
       struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       unsigned short  *array;  /* Array for GETALL, SETALL */
       struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

struct sembuf sem_op;
union semun sem_union;

int main(){
    int i,j;
    sem_id = semget((key_t)1234,1,0666|IPC_CREAT);

    for(i=0;i<=10;i++){
        get_semaphore();
        printf("\nSEM2:%d:got the semaphore\n",getpid());
        for(j=0;j<=3;j++){
            sleep(1);
            printf("\a");
        }
        printf("\nSEM2:%d:got the semaphore\n",getpid());
        release_semaphore();
        sleep(2);
    }
}