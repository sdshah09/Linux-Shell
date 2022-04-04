#include<stdio.h>
#include<signal.h>

void check_pending_sighand(sigset_t s){
    int i,res;
    for(i=1;i<5;i++){
        res=sigismember(&s,i);
        if(res){
            printf("signal %d is pending \n",i);
        }
        else{
            printf("signal %d is not pending\n",i);
        }
    }
}

void sighand(int no){
    printf("I am in sighnadler\n");
}

int main(){
    sigset_t s_set ,s; //! group of signals
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
    sigpending(&s);
    check_pending_sighand(s);
    getchar();
    sigprocmask(SIG_UNBLOCK,&s_set,NULL);
    printf("Now signals are unblocked\n");
    while(1);
}