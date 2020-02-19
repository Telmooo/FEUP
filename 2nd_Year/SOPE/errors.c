#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFF_LENGTH 256

int main(int argc, char *argv[]) {
    FILE *src, *dst;
    char buf[BUFF_LENGTH];
    char error[BUFF_LENGTH];

    if (argc != 3) {
        printf("usage: executable file1 file2\n");
        sprintf(error, "Error %d", errno);
        perror(error);
        exit(0);
    }

    if ((src = fopen(argv[1], "r")) == NULL) {
        sprintf(error, "Error %d", errno);
        perror(error);
        exit(1);
    }
    if ((dst = fopen(argv[2], "w")) == NULL) {
        sprintf(error, "Error %d", errno);
        perror(error);
        exit(2);
    }
    while ((fgets(buf, BUFF_LENGTH, src)) != NULL) {
        fputs(buf, dst);
    }
    fclose(src);
    fclose(dst);
    sprintf(error, "Error %d", errno);
    perror(error);
    exit(0);
}
