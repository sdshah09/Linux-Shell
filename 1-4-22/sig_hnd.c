#include<stdio.h>
#include<signal.h>

void sighnd(int signum){
    printf("Interrupt signal recorder but no termination ctrl+c\n");
    signal(SIGINT,SIG_DFL);
}

int main(){
    int i;
    signal(SIGINT,sighnd);
    for(i=0;;i++){
        printf("%d\n",i);
        sleep(1);
    }
    
}