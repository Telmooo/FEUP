#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFER_SIZE     256
#define READ            0
#define WRITE           1

int main(void) {

    int pipe_fd[2];

    if (pipe(pipe_fd)) { write(STDERR_FILENO, "pipe error\n", 12); return -1; }

    pid_t pid = fork();

    if (pid < 0) { write(STDERR_FILENO, "fork error\n", 12); return -1; }
    else if (pid > 0) { // parent
        int write_int[2];
        write(STDOUT_FILENO, "Parent:\nx y ? ", 15);
        scanf("%d %d", &write_int[0], &write_int[1]);
        close(pipe_fd[READ]);
        write(pipe_fd[WRITE], write_int, sizeof(int) * 2);
        close(pipe_fd[WRITE]);
        kill(pid, SIGCONT);
        wait(NULL);
    } else { // child
        int read_int[2];
        raise(SIGSTOP);
        close(pipe_fd[WRITE]);
        read(pipe_fd[READ], read_int, sizeof(int) * 2);
        close(pipe_fd[READ]);
        write(STDOUT_FILENO, "Child\n", 7);
        printf("x + y = %d\n", read_int[0]+read_int[1]);
    }
    return 0;
}
