#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10
void* thrfunc(void * arg) {
    int i;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    for (i = 1; i <= NUMITER; i++) write(STDERR, arg, 1);
    return NULL;
}
int main() {
    pthread_t ta, tb;
    char c = '1';
    pthread_create(&ta, NULL, thrfunc, &c);
    c = '2';
    pthread_create(&tb, NULL, thrfunc, &c);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}
