#include <stdio.h>
#include <stdlib.h>

void handler1(void) {
    printf("Executing exit handler 1\n");
}

void handler2(void) {
    printf("Executing exit handler 2\n");
}

int main(void) {
    atexit(handler2);
    atexit(handler1);

    printf("Main done\n");

    return 0;
}
