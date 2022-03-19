#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Execute ls program\n");
    
    execl("/bin/ls","ls","-lh",0);

    printf("Executed ls program");
    printf("Executed ls program");
    printf("Executed ls program");
}