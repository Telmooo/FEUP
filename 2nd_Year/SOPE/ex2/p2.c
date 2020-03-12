#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

    if (argc != 2 && argc != 3) {
        char error_msg[BUFFER_SIZE];
        sprintf(error_msg,  "Error: Wrong number of arguments\n"
                            "Program usage: %s <source> <destination> -> copies from source to destination\n"
                            "               %s <source> -> shows content from source file\n" , argv[0], argv[0]);
        write(STDOUT_FILENO, error_msg, strlen(error_msg));
        return EPERM;
    }

    const int DEFAULT_MODE = 0644;

    int filedes1 = open(argv[1], O_RDONLY);

    if (filedes1 == -1) {
        perror("Error: source file isn't a valid path");
        return ENOENT;
    }

    int filedes2;
    if (argc == 3) {
        filedes2 = open(argv[2], O_WRONLY | O_CREAT, DEFAULT_MODE);

        if (filedes2 == -1) {
            close(filedes1);
            perror("Error: destination file isn't a valid path");
            return ENOENT;
        }
    } else {
        filedes2 = dup(STDOUT_FILENO);
    }

    char buffer[BUFFER_SIZE];
    int ch_read, ch_write;

    while ((ch_read = read(filedes1, buffer, BUFFER_SIZE)) > 0) {
        if ((ch_write = write(filedes2, buffer, ch_read)) <= 0 || ch_write != ch_read) {
            if (close(filedes1)) perror("Error: couldn't close source file correctly");
            if (argc == 3)
                if (close(filedes2)) perror("Error: coudln't close destination file correctly");
            return EINTR;
        }
    }

    if (close(filedes1)) {
        perror("Error: couldn't close source file correctly");
        if (argc == 3)
            if (close(filedes2)) perror("Error: coudln't close destination file correctly");
        return EINTR;
    }
    if (argc == 3) {
        if (close(filedes2)) {
            perror("Error: coudln't close destination file correctly");
            return EINTR;
        }
    }

    return 0;
}
