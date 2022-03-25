#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int fd[2];
int i,res;

void parent(){
    int n1,n2;
    char *buf1="sssssssssss";
    char *buf2 = "ddddddddddd\n";
    n1 = strlen(buf1);
    n2 = strlen(buf2);
    close(fd[0]);
    write(fd[1],buf1,n1);
    write(fd[1],buf2,n2);
    printf("end of parent:\n"); 
}

void child(){
    char buf[100];
    int n,i;
    close(fd[1]);
    n = read(fd[0],buf,100);
    printf(" no of char read = %d\n",n);
    for(i=0;i<n;i++){
        printf("%c",buf[i]);
    }
    printf("end of child\n");
}

int main(){
    pid_t p;
    res = pipe(fd);
    if(res==-1){
        perror("pipe");
        exit(1);
    }

    p=fork();
    if(p==0){
        child();
    }
    else{
        parent();
    }
}