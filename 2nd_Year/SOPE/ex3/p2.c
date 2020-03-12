#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
    //write(STDOUT_FILENO, "1", 1);
    printf("1\n");
    if(fork() > 0) {
        //write(STDOUT_FILENO, "2", 1);
        printf("2");
        //write(STDOUT_FILENO, "3", 1);
        printf("3");
    } else {
        //write(STDOUT_FILENO, "4", 1);
        printf("4");
        //write(STDOUT_FILENO, "5", 1);
        printf("5");
    }
    //write(STDOUT_FILENO, "\n", 1);
    printf("\n");
    return 0;
}
