#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int f2,f3;
	char c[50];
	f2 = open("Linux2.txt",O_RDONLY ,777);
	f3 = open("Linux3.txt",O_RDWR | O_APPEND,777);
	if(f2&&f3<0){
		printf("Cannot open\n");
	}
read(f2,c,50);
write(f3,c,50);
printf("c = %s",c);

int close(int f2);
int close(int f3);
}
