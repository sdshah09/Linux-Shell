#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(void){
    printf("client process writing\n");
    char clientmsg[] = "Linux System Kernel Programming";
    int fd = open("cli_Ser_fifo",O_WRONLY);
    if(fd==-1){
        perror("Cannot open fifo");
        return EXIT_FAILURE;
    }
    write(fd,clientmsg,strlen(clientmsg));
    close(fd);
    return 0;
}