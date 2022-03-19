#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        //executable file named 2 is needed to run this program
        int ret = execl("/home/shaswat/Desktop/project/process assignment/3",NULL);
    }
    else{
        wait(0);
        printf("parent running\n");
    }
}