#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main() 
{ 
    int n;
    printf("Enter the number of processes you want: ");
    scanf("%d",&n);
    // printf("[parent] pid %d\n",getppid());
    for(int i=0;i<n-1;i++) 
    {  
        pid_t s=fork();
        if(s == 0) 
        { 
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid()); 
            exit(0); 
        } 
    } 
    for(int i=0;i<n-1;i++) 
    wait(NULL); 

} 
