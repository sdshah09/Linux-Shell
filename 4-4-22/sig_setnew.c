#include<stdio.h>
#include<signal.h>

void sighand(signal){
    printf("Interrupt signal rec'd... but no termination on ctrl+c\n");

    if(signal==SIGINT){
        printf("Received a SIGINT signal\n");
        exit(0);
    }
}

int main(){
    int i;
    signal(SIGINT,sighand);
    
}