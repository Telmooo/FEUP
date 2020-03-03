#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    struct termios term, old_term;

    tcgetattr(STDOUT_FILENO, &old_term);
    term = old_term;
    term.c_lflag &= ~( ECHO | ECHOE | ECHOK | ECHONL | ICANON );
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &term);

    if (argc != 3) {
        perror("Error: Wrong number of arguments\n"
                             "Program usage: ./copy file1 file2 -> copies from file1 (source) to file2 (destination)");

        return EPERM;
    }

    const char DEFAULT_MODE = 0644;

    int filedes1 = open(argv[1], O_RDONLY);

    if (filedes1 == -1) {
        perror("Error: source file isn't a valid path");
        return ENOENT;
    }

    int filedes2 = open(argv[2], O_WRONLY, DEFAULT_MODE);

    if (filedes2 == -1) {
        perror("Error: destination file isn't a valid path");
        return ENOENT;
    }

    return 0;
}
