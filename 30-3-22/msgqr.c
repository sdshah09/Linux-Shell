#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/msg.h>

typedef struct
{
    long msgtype;
    char buffer[100];
} msg;
int main()
{
    int qid;
    int i;
    msg m1, m2;
    qid = msgget(55, IPC_CREAT | 0644);
    i = msgrcv(qid, &m1, sizeof(m1), 10, 0);
    for (i = 0; i < 100;i ++)
    {
        printf("%c", m1.buffer[i]);
    }
    printf("\n");
    i = msgrcv(qid, &m2, sizeof(m2), 20, 0);
    for (i = 0; i < 100; i++)
    {
        printf("%c", m2.buffer[i]);
    }
    printf("\n");
}