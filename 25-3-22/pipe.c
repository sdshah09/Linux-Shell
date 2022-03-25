#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd[2];
    int i,res;
    char *buf1="sssssssssss";
    char *buf2 = "dddddddddddddd";
    char buf[30];

    res = pipe(fd);
    if(res==-1){
        perror("pipe");
        exit(1);
    }

    write(fd[1],buf1,20);
    write(fd[1],buf2,20); //! for write = 1
    read(fd[0],buf,30); //todo: for read = 0

    for(i=0;i<30;i++){
        printf("%c",buf[i]);
    }
    printf("\n");
}
