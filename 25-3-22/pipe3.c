#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int p[2];
    pipe(p);
    printf("Read end of pipe = %d\t Write end of pipe = %d\n",p[0],p[1]);
    if(fork()){
        char s[20];
        printf("In parent enter data\n");
        scanf("%s",s);
        write(p[1],s,strlen(s)+1);
    }

    else{
        char buf[20];
        printf("In child...\n");
        read(p[0],buf,sizeof(buf));
        printf("child pro printing data. Data of the parent proccess..%s\n",buf);
    }

    return 0;
}