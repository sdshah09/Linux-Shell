#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(){
    int fd;
    mkfifo("newfifo",0666);
    char arr1[100],arr2[100];
    while(1){
        fd=open("newfifo",O_WRONLY);
        fgets(arr2,100,stdin);
        write(fd,arr2,strlen(arr2)+1);
        close(fd);
        fd=open("newfifo",O_RDONLY);
        read(fd,arr1,sizeof(arr1));
        printf("User2: %s\n",arr1);
        close(fd);
    }
    return 0;
}