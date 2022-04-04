#include<stdio.h>
#include<signal.h>

void sighand(int signum){
    printf("Wake up\n");
}

int main(){
    signal(SIGALRM,sighand);
    alarm(3);
    while(1){

    }
}