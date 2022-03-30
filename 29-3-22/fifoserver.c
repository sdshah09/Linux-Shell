#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(void){
    printf("Server Listening");
    int code = mkfifo("cli_ser_fifo",0777);
    if(code==-1){
        perror("mkfifo returned an error - file may already exist");
    }
    int fd = open("cli_ser_fifo",O_RDONLY);
    if(fd==-1){
        perror("cannot open FIFO fo read"); 
        return 0;

printf("FIFO Open");
char servercv[100];
memset(servercv,0,100);
int res;
char len;
while(1){
    res = read(fd,&len,1);
    if(res==0){
        break;
    }
    read(fd,servercv,len);
    printf("Server received: %s\n",servercv);
}
printf("EOF reached");
close(fd);
printf("FIFO Closed");
return 0;
}
}
