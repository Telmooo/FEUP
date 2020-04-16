#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10
void *PrintHello(void *threadnum) {
    printf("Hello from thread no. %d!\n", *(int *) threadnum);
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    int t;
    int num[NUM_THREADS];
    for(t=0; t< NUM_THREADS; t++){
        printf("Creating thread %d\n", t+1);
        num[t] = t+1;
        pthread_create(&threads[t], NULL, PrintHello, (void *)&num[t]);
    }
    exit(0);
}
