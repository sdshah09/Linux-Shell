#include<sys/types.h>
#include<stdio.h>
#include<signal.h>

void sig_handler(int signum){
	printf("Inside handler function\n");
}
int main(){
    pid_t pid;
    signal(SIGUSR1,sig_handler); // ! Register signal handler
    printf("Inside main function\n");
    pid=getpid();
    kill(pid,SIGUSR1);
    printf("Inside main function\n");
    return 0;
}
