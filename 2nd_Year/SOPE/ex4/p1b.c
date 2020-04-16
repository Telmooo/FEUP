#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
}

int main(void) {
    if (signal(SIGINT, sigint_handler) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    printf("Sleeping for 30 seconds ...\n");
    int time_left = 30;

    while (time_left) {
        time_left = sleep(time_left);
        printf("%d seconds left\n", time_left);
    }
    printf("Waking up ...\n");
    exit(0);
}
