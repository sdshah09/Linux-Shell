#include<stdio.h>
#include<signal.h>

void sighand(int no){
    printf("I am in sighandler\n");
}

int main(){
    sigset_t s_set; //! group of signals
    signal(2,sighand); 
    sigemptyset(&s_set); //todo initialize the signal set s_set
    sigaddset(&s_set,2);
    perror("sig2");
    sigaddset(&s_set,4);
    perror("sig4");
    sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL); 
    perror("sigmask");
    printf("send me signal one ans see the effect now\n");
    // getchar();
    getchar();
    sigprocmask(SIG_UNBLOCK,&s_set,NULL);
    printf("Now signals are unblocked\n");
    while(1);
}