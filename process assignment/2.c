//2.Write a program such that parent process create two child processes,such that each child
//executes a separate task.


#include<stdio.h>


int main()
{
	for(int i=0;i<2;i++) 
	{
		if(fork() == 0)
		{
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
			exit(0);
		}
	}
	for(int i=0;i<2;i++) 
	wait(NULL);
	
}
