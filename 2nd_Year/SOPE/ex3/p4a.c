#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void) {

    int pid = fork();

    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0:
            write(STDOUT_FILENO, "Hello ", 6);
            break;
        default:
            waitpid(pid);
            write(STDOUT_FILENO, "world!", 6);
            break;
    }
    return 0;
}
