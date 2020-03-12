#include <sys/unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    int fd;
    char *text1 = "CCCCC";
    char *text2 = "DDDDD";
    fd = open("f1.txt", O_WRONLY | O_SYNC, 0600);
    if (errno != 0) {
        char *error = strerror(errno);
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Error %d: %s\n", errno, error);
        write(STDERR_FILENO, buffer, strlen(buffer));
        return errno;
    }
    getchar();
    write(fd, text1, 5);
    if (errno != 0) {
        char *error = strerror(errno);
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Error %d: %s\n", errno, error);
        write(STDERR_FILENO, buffer, strlen(buffer));
        return errno;
    }
    getchar();
    write(fd, text2, 5);
    if (errno != 0) {
        char *error = strerror(errno);
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Error %d: %s\n", errno, error);
        write(STDERR_FILENO, buffer, strlen(buffer));
        return errno;
    }
    close(fd);
    return 0;
}
