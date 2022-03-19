#include<stdio.h>
#include<unistd.h>

int main(){
    int ret;
    ret = execl("/usr/bin/vim","vi","info1.txt",0);
    if(ret==-1){
        printf("execl returned error %d\n",ret);
    }
}