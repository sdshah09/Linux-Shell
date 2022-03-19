#include<stdio.h>
#include<string.h>


int main(){
    char src[7] = "linux";
    char dst[7];
    mymemcopy(src,dst,7);
    printf("destination using source is %s\n",dst);
    return 0;
}


void mymemcopy(char *src,char *dst,int count){
    int i;
    for(i=0;i<count;i++){
        *dst = *src;
        dst++;
        src++;
    }
}