#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

#define NUM_THREADS 10

void* thrfunc(void * arg) {
    sleep(1);
    /*
    // Can also be used via syscall (OS dependent)
    int tid;
    #ifdef SYS_gettid
    tid = syscall(SYS_gettid);
    #else
    tid = *(int*)arg;
    #endif
    */
    fprintf(stderr, "tid: %lu - number of order: %d\n", pthread_self(), *(int*)arg);
    /**
    fprintf(stderr, "tid: %d - number of order: %d\n", tid, *(int*)arg);
    **/
    void *ret = malloc(sizeof(int));
    *(int*)ret = *(int*)arg;
    return ret;
}
int main() {
    pthread_t tid[NUM_THREADS];
    int arg[NUM_THREADS], *ret[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        arg[i] = i;
        pthread_create(&tid[i], NULL, thrfunc, (void*)&arg[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], (void*)&ret[i]);
        fprintf(stderr, "Thread %d finished\n", *(int*)ret[i]);
        free(ret[i]);
    }

    pthread_exit(0);
}
