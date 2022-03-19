#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd1,fd2,fd3,fd4;
	//umask(0);
	fd1=open("linux.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd2=open("linuxnew.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("fd1 = %d\n",fd1);
	printf("fd1 = %d\n",fd2);
	fd3 = dup(fd2);
	printf("dup of fd3 is: %d\n",fd3);

	int close(int fd1);
	int close(int fd2);
	int close(int fd3);

}	