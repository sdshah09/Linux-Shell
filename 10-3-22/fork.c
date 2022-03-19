#include<stdio.h>

#include<unistd.h>

int main(void){
    int pid1;

    printf("CUrrent process pid = %d\n",getpid());

    //pid1 = vfork();
    pid1 = fork();
    if(pid1==0){
        //sleep(3); sleep for necessary seconds
        //execl("/bin/ls","ls","-lh",0);
        printf("new child process pid = %d\n ",getpid());
        printf("new child parent process ppid = %d\n",getppid());
        
    }
    else if(pid1!=0){
        printf("new child process pid = %d\n ",getpid());
        printf("new child parent process ppid = %d\n",getppid());   
    }
    else{
        printf("parent process pid = %d\n",getpid());
        printf("new parent parent's process ppid = %d\n",getppid());

    }
    while(1){
        return 0;
    }
}
