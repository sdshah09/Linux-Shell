#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *s1 = "linux";
    char *s2 = "kernel";

    char *name = (char *)alloca(strlen(s1) + strlen(s2) + 1);
    strcat(strcpy(name,s1),s2);

    printf("the copied string data is = %s \n",name);
    return 0;
}
