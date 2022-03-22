#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int i;
    printf("\n file name: %s\n",argv[0]);
    printf("\n total number of arguments: %d",argc);
    printf("\n arguments passed: ");
    for(i=1;i<argc;i++){
        printf(" %s ",argv[i]);
    }
    printf("\n");
}

//1. r emb linux kernel program:- to pass the arguments and running the programs
//2. gdb --args ./a.out linux kernel program:- pass arguments from the start 
//3. set args one two three:- it is the third way to provide arguments in gdb.
