#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LENGTH  30

int main(void) {

    struct termios term, old_term;

    const char NULL_CHAR = 0x00;
    const char DELETE = 0x7F;
    const char BACKSPACE = 0x08;
    const char NEW_LINE = 0x0A;
    const char SPACE = 0x20;

    char password[MAX_LENGTH + 1], ch, echo = '*';

    tcgetattr(STDOUT_FILENO, &old_term);
    term = old_term;
    term.c_lflag &= ~ (ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &term);

    int i = 0;

    while (read(STDIN_FILENO, &ch, 1) && ch != NEW_LINE) {
        if (ch == DELETE) {
            if (i <= 0) continue;
            write(STDOUT_FILENO, &BACKSPACE, 1);
            write(STDOUT_FILENO, &SPACE, 1);
            write(STDOUT_FILENO, &BACKSPACE, 1);
            password[--i] = NULL_CHAR;
        } else {
            if (i == MAX_LENGTH) continue;
            password[i++] = ch;
            write(STDOUT_FILENO, &echo, 1);
        }
    }
    password[i] = NULL_CHAR;
    write(STDOUT_FILENO, &NEW_LINE, 1);

    for (int j = 0; j < i; j++) {
        write(STDOUT_FILENO, &password[j], 1);
    }

    write(STDOUT_FILENO, &NEW_LINE, 1);

    tcsetattr(STDOUT_FILENO, TCSANOW, &old_term);

    return 0;
}
