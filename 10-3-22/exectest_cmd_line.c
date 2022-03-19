/* This program explains how to manipulate command line arguments*/

#include<stdio.h>
int main(int argc,char *argv[]){
    int i;
    printf("\n FIle name: %s\n",argv[0]); // argument value
    printf("\n Total number of arguments: %d",argc); // number of arguments passed
    printf("\nArguments passed: ");    
    for(i=1;i<argc;i++){
        printf(" %s ",argv[i]);
    }
    return 0;
}