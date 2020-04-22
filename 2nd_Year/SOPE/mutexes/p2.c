#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2

int N = 1000;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void* thrfunc(void * arg) {
    void *counter = malloc(sizeof(int));
    *(int*)counter = 0;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    while (N > 0) {
        pthread_mutex_lock(&mut);
        if (N <= 0) {
            pthread_mutex_unlock(&mut);
            break;
        }
        N--;
        pthread_mutex_unlock(&mut);
        write(STDERR, arg, 1);
        (*(int*)counter)++;
    }
    return counter;
}
int main() {
    pthread_t ta, tb;
    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");
    void *counter1, *counter2;
    pthread_join(ta, &counter1);
    pthread_join(tb, &counter2);

    write(STDERR, "\n", 1);

    fprintf(stderr, "Thread 1 wrote: %d chars\n", *(int*)counter1);
    fprintf(stderr, "Thread 2 wrote: %d chars\n", *(int*)counter2);

    free(counter1);
    free(counter2);

    return 0;
}
