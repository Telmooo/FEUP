#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE     256

int main(int argc, int *argv[]) {

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

    const char NEW_LINE = 0x0A;
    const char ESC = 0x1B;
    const char DELETE = 0x7F;
    const char deleteChar[] = "\b \b";

    char buffer[BUFFER_SIZE + 1];
    char ch;

    int ch_read;

    while (1) {
        write(STDOUT_FILENO, "Student name: ", 14);

        ch_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        

    }

    return 0;
}
