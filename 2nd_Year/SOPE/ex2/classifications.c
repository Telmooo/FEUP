#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define BUFFER_SIZE     256

int main(int argc, char *argv[]) {

    if (argc != 2) {
        char error[BUFFER_SIZE];
        sprintf(error, "Error: Wrong number of arguments\n"
                       "       Program usage: %s <destination>\n", argv[0]);
        perror(error);
        return EPERM;
    }

    const int DEFAULT_MODE = 0644;

    int filedes = open(argv[1], O_WRONLY | O_CREAT, DEFAULT_MODE);

    if (filedes == -1) {
        perror("Error: couldn't open destination file\n");
        return ENOENT;
    }

    const char ESCAPE = 0x1B;

    char buffer[BUFFER_SIZE + 1];

    int ch_read, ch_write;

    while (1) {
        write(STDOUT_FILENO, "Student name: ", 14);

        ch_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (ch_read == 1 || (ch_read == 2 && buffer[0] == ESCAPE)) {
            break;
        }

        if (ch_read < 0) {
            close(filedes);
            perror("Error: couldn't read keyboard input\n");
            return EIO;
        }

        ch_write = write(filedes, buffer, ch_read - 1);

        if (ch_write != ch_read - 1) {
            perror("Error: couldn't write to file correctly\n");
            close(filedes);
            return EIO;
        }


        write(STDOUT_FILENO, "Student grade: ", 15);

        ch_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (ch_read < 0) {
            close(filedes);
            perror("Error: couldn't read keyboard input\n");
            return EIO;
        }
        write(filedes, " - ", 3);
        if (ch_read == 1) {
            write(filedes, "0\n", 2);
        } else {
            ch_write = write(filedes, buffer, ch_read);

            if (ch_write != ch_read) {
                perror("Error: couldn't write to file correctly\n");
                close(filedes);
                return EIO;
            }
        }
    }
    close(filedes);

    return 0;
}
