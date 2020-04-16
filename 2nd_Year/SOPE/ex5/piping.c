/* SYSTEM CALLS  HEADERS */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* C LIBRARY HEADERS */
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_PIPE 0
#define WRITE_PIPE 1

int main(int argc, char *argv[]) {

    int stdpipe[2];

    int sizepipe[2];


    pipe(stdpipe); pipe(sizepipe);

    int subprocess = 0;

    int fsize = 0;

    {
        struct stat stdout_status;
        struct stat stdin_status;
        if (fstat(STDOUT_FILENO, &stdout_status) || fstat(STDIN_FILENO, &stdin_status)) {
            return 1;
        }
        printf("stdout: %x\nstdin: %x\n", stdout_status.st_mode & S_IFMT, stdin_status.st_mode & S_IFMT);
        if ((stdout_status.st_mode & S_IFMT) == S_IFIFO && (stdin_status.st_mode & S_IFMT) == S_IFIFO) {
            int std[2];
            read(STDIN_FILENO, &std, sizeof(int) * 2);
            if (dup2(STDOUT_FILENO, sizepipe[WRITE_PIPE]) == -1 || dup2(STDIN_FILENO, stdpipe[READ_PIPE]) == -1) {  // where child should write to ||  where child should read from
                return 2;
            }
            if (dup2(std[READ_PIPE], STDIN_FILENO) == -1 || dup2(std[WRITE_PIPE], STDOUT_FILENO) == -1) {
                return 3;
            }
            subprocess = 1;
            printf("subprocess\n");
        }
    }
    if (strcmp(argv[1], "finish") != 0) {
        int return_status;
        pid_t pid = fork();

        if (pid == 0) {
            //child
            int std[2];
            std[READ_PIPE] = dup(STDIN_FILENO);
            std[WRITE_PIPE] = dup(STDOUT_FILENO);
            if (write(stdpipe[WRITE_PIPE], &std, sizeof(int) * 2) == -1) {
                return 4;
            }
            if (close(sizepipe[READ_PIPE]) || close(stdpipe[WRITE_PIPE])) {
                return 5;
            }

            dup2(sizepipe[WRITE_PIPE], STDOUT_FILENO);
            dup2(stdpipe[READ_PIPE], STDIN_FILENO);
            argv[1] = "finish";
            execv(argv[0], argv);
        } else if (pid > 0) {
            // parent
            if (waitpid(pid, &return_status, 0) == -1) {
                return 6;
            }

            write(STDOUT_FILENO, "finished waiting\n", 18);

            if (!WIFEXITED(return_status)){
                return 7;
            }
            if (WEXITSTATUS(return_status) != 0) {
                return 8;
            }
            int subdir_size = 0;
            printf("teste\n");
            struct stat thistat;
            fstat(sizepipe[READ_PIPE], &thistat);
            if ((thistat.st_mode & S_IFMT) == S_IFIFO) {
                printf("é pipe\n");
            }
            read(sizepipe[READ_PIPE], &subdir_size, sizeof(int));
            printf("%d\n", subdir_size);
            fsize += subdir_size;
            printf("teste2\n");
        }
    }

    fsize += 20;
    if (subprocess) {
        write(sizepipe[WRITE_PIPE], &fsize, sizeof(int));
    }

    printf("Processo %d: fsize = %d\n", getpid(), fsize);
    printf("Exiting...\n");
    sleep(10);
    return 0;
}
