#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

#define NUM_THREADS 10

void* dadd(void * arg) {
    void *ret = malloc(sizeof(double));

    *(double*)ret = *((double*)arg) + *((double*)arg + 1);

    return ret;
}

void* dsub(void * arg) {
    void *ret = malloc(sizeof(double));

    *(double*)ret = *((double*)arg) - *((double*)arg + 1);

    return ret;
}

void* dmul(void * arg) {
    void *ret = malloc(sizeof(double));

    *(double*)ret = *((double*)arg) * *((double*)arg + 1);

    return ret;
}

void* ddiv(void * arg) {
    void *ret = malloc(sizeof(double));

    *(double*)ret = *((double*)arg) / *((double*)arg + 1);

    return ret;
}

int main() {
    pthread_t tadd, tsub, tmul, tdiv;
    double args[2];

    printf("Enter two numbers: ");
    scanf("%lf %lf", &args[0], &args[1]);

    pthread_create(&tadd, NULL, dadd, (void*)args);
    pthread_create(&tsub, NULL, dsub, (void*)args);
    pthread_create(&tmul, NULL, dmul, (void*)args);
    pthread_create(&tdiv, NULL, ddiv, (void*)args);

    double *ret;
    pthread_join(tadd, (void*)&ret);
    fprintf(stderr, "Result of addition: %lf\n", *(double*)ret);
    free(ret);

    pthread_join(tsub, (void*)&ret);
    fprintf(stderr, "Result of subtraction: %lf\n", *(double*)ret);
    free(ret);

    pthread_join(tmul, (void*)&ret);
    fprintf(stderr, "Result of multiplication: %lf\n", *(double*)ret);
    free(ret);

    pthread_join(tdiv, (void*)&ret);
    fprintf(stderr, "Result of division: %lf\n", *(double*)ret);
    free(ret);

    pthread_exit(0);
}
