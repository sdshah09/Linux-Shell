/*
4.A processs using execl() system call should replace a new command line program.
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
     execl(argv[1],0);
}
