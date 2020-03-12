#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define BUFFER_SIZE     255
#define NAME_SIZE       50

struct person {
    char name[NAME_SIZE];
    int  classification;
};

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
    const char NEW_LINE = 0x0A;
    const char NULL_CHAR = 0x00;

    struct person p;

    int ch_read;

    while (1) {
        write(STDOUT_FILENO, "Student name: ", 14);

        ch_read = read(STDIN_FILENO, p.name, NAME_SIZE);

        if (ch_read == 1 || (ch_read == 2 && p.name[0] == ESCAPE)) {
            break;
        }

        if (p.name[ch_read - 1] == NEW_LINE) p.name[ch_read - 1] = NULL_CHAR;

        if (ch_read < 0) {
            close(filedes);
            perror("Error: couldn't read keyboard input\n");
            return EIO;
        }

        write(STDOUT_FILENO, "Student grade: ", 15);

        ch_read += read(STDIN_FILENO, &p.classification, sizeof(int));

        if (ch_read < 0) {
            close(filedes);
            perror("Error: couldn't read keyboard input\n");
            return EIO;
        }

        write(filedes, &p, sizeof(struct person));
    }
    close(filedes);

    return 0;
}
