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
                       "       Program usage: %s <source>\n", argv[0]);
        perror(error);
        return EPERM;
    }

    int filedes = open(argv[1], O_RDONLY);

    if (filedes == -1) {
        perror("Error: couldn't open source file\n");
        return ENOENT;
    }

    struct person p;

    int ch_read;

    ch_read = read(filedes, &p, sizeof(struct person));

    write(STDOUT_FILENO, p.name, strlen(p.name));
    write(STDOUT_FILENO, " - ", 3);
    write(STDOUT_FILENO, &p.classification, sizeof(int));

    close(filedes);

    return 0;
}
