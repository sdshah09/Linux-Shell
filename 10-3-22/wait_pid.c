#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int pid;
    int status;

    printf("Parent = %d\n",getpid());

    pid = fork();
    if(pid==0){
        printf("Child %d\n",getpid());
        sleep(2);

        exit(0);
    }
    printf("Parent reporting exit of xhild whose pid= %d\n",waitpid(pid,&status,0));
    return 0;
}