#include <stdio.h>
#include <pthread.h>

static pthread_spinlock_t spinlock;
int s;

int i = 1;
void *inc(void *num)
{

    long th_id;
    th_id = (long)num;
    printf("THREAD: %ld \n", th_id);
    pthread_spin_lock(&s);
    printf("'i' is locked\n");
    i++;
    sleep(1);
    printf("i: %d\n", i);
    printf("'i' is unlocked\n\n");
    pthread_spin_unlock(&s);
    return NULL;
}

void *dec(void *num)
{

    long th_id;
    th_id = (long)num;
    printf("THREAD: %ld\n", th_id);
    pthread_spin_lock(&s);
    printf("'i' is locked\n");
    i--;
    sleep(1);
    printf("i: %d\n", i);
    printf("'i' is unlocked\n\n");
    pthread_spin_unlock(&s);
    return NULL;
}
int main()
{
    pthread_t thread[3];
    if (pthread_spin_init(&s, PTHREAD_PROCESS_PRIVATE) != 0)
    {
        perror("init");
    }

    for (int i = 1; i <= 3; i++)
    {
        if (i % 2 == 0)
        {
            sleep(1);
            pthread_create(&thread[i], NULL, inc, (void *)i);
        }
        else
        {
            sleep(1);
            pthread_create(&thread[i], NULL, dec, (void *)i);
        }
    }
    pthread_exit(NULL);
    return 0;
}