#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd,len;
	char c[30] = "Hi how are you????????";
	char b[30];

	fd = open("linux_kernel.txt", O_CREAT | O_RDWR,777);

	len = write(fd,c,30);

	printf("return value from write is = %d\n",len);

	lseek(fd, 10, SEEK_SET);
	lseek(fd, 5, SEEK_END);
	lseek(fd, 0, SEEK_CUR);
	read(fd, c, len);
printf("read buffer value is: %s\n", c);




int close(int fd4);

	return 0;
}