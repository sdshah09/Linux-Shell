#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int pi[2];
    pipe(pi);
    printf("Read end of pipe = %d\t Write end of pipe = %d\n",pi[0],pi[1]);
    if(fork()){
        char s[20];
        printf("In parent enter data\n");
        scanf("%s",s);
        write(pi[1],s,strlen(s)+1);
    }

    else{
        char buf[20];
        int i;
        for(i=0;i<2;i++){
        printf("In child...\n");
        read(pi[i],buf,sizeof(buf));
        printf("child pro printing data. Data of the parent proccess..%s\n",buf);
     }
    }

    return 0;
}