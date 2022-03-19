#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "linuxkernel.com.com";
    char ch[] = "einfochips.com";

    printf("before destination str = %s,ch=%s\n ",str,ch);
    memmove(str,ch,15);
    printf("after destination str = %s,ch=%s\n ",str,ch);
}