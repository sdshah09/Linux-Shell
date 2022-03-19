#include<stdio.h>
#include<string.h>

int main(){
    const char str[] = "linuxkernel.com";
    const char ch = '.';
    char *ret;

    printf("String before set/initialization is %s \n",str);

    ret = memrchr(str,ch,strlen(str));

    
    printf("string after **%c** is - **%s**\n",ch,ret+5);
    return 0;
}