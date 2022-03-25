#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(){
    char s[20];
    int fd;

    mkfifo("newfifo1",0644);
    // perror("mkfifo");

    printf("Befoe open()\n");
    fd = open("newfifo1",O_RDONLY);
    printf("After open()\n");

    // printf("Enter data: \n");
    // scanf("%s",s);
    read(fd,s,sizeof(s));
    printf("Data: %s\n",s);
    return 0;
}