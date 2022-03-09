#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
	struct stat st;
	int fd;

	stat("lseek.c",&st);
	printf("File size = %lu\n",(st.st_size)); // ls -l
	printf("File inode = %lu\n",(st.st_ino));
	printf("File size of blocks = %lu\n",(st.st_blksize));

	printf("\n\n");
	close(fd);
	return 0;
}