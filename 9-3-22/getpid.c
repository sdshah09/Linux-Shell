#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("my process pid %d\n ",getpid());
    printf("my parent pid %d\n",getppid());
    while(1){
        return 0;
    }
}   