#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int f2,len,f3;
	char c[30] = "Hi how are you????????";
	char b[30];

	f3 = creat("Linux4.txt",777);
	f2 = open("Linux2.txt",O_CREAT | O_RDWR,777);

	len = write(f3,c,30);

	printf("return value from write is = %d\n",len);

	lseek(f3, 10, SEEK_SET);
	lseek(f3, 5, SEEK_END);
	lseek(f3, 0, SEEK_CUR);
	read(f3, c, len);
printf("read buffer value is: %s\n", c);




int close(int fd4);

	return 0;
}