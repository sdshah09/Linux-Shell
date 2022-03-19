#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/mman.h>
#include <sys/stat.h>

int main(){
    int fd;
    char *c;
    struct stat file_info;
    fd = open("kernel.txt",O_CREAT|O_RDWR,777);
    write(fd,"linux kernel technology",25);

    fstat(fd,&file_info);
    printf("file size is %ld\n",file_info.st_size);
    
    c=mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
    perror("mmap");
    printf("%s\n",c);

    munmap(c,file_info.st_size);
    close(fd);
    return 0;

}