#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char buff_comm[5];
    strcpy(buff_comm,"ls -l");

    printf(" system() library function uses fork() to create a child process\n");
    printf("child process executes execl() which loads and run new program provided by system() argument\n");
    // system(buff_comm);
    // printf("%d\n",system(NULL)); //! will return value 1 because there is no process going on
    printf("%d\n",system(buff_comm)); //todo: will return value 0 because the system is going thorugh ls-l process
    return 0;
}