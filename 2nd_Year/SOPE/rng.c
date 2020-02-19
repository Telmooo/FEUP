#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    struct tms *start, *end;
    times(start);
    if (argc != 3) {
        printf("usage: executable n1 n2\nNote: n1 must be greater than n2\n");
        return 0;
    }

    int n1, n2, guess, iter = 0;
    const int ticks_seg = sysconf(_SC_CLK_TCK);

    sscanf(argv[1], "%d", &n1);
    sscanf(argv[2], "%d", &n2);

    if (n2 >= n1) {
        printf("usage: executable n1 n2\nNote: n1 must be greater than n2\n");
        return 0;
    }
    srand(time(NULL));
    while (1) {
        guess = rand() % n1;
        if (guess == n2) {
            printf("Generated number %d after %d iterations\n", n2, iter);
            break;
        }
        iter++;
    }
    times(end);
    clock_t user_time = end->tms_utime - start->tms_utime;
    clock_t system_time = end->tms_stime - start->tms_stime;

    printf("CPU Time\nUser: %d\nSystem: %d\n", user_time/ticks_seg, system_time/ticks_seg);
    return 0;
}
