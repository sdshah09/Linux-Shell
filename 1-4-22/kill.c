#include<sys/types.h>
#include<stdio.h>
#include<signal.h>

int main(){
    pid_t pid;
    int sig_no;
    printf("enter the pid of th eprocess for which the signal need to be semt: ");
    scanf("%d",&pid);
    printf("Enter the signal that need to be sent: ");
    scanf("%d",&sig_no);
    kill(pid,sig_no);
    perror("Sig_res");
}