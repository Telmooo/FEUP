#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    const int BUFFER_LENGTH = 256;
    const int MAX_TOKENS = 100;
    const int MAX_CMD = 10;

    char str[BUFFER_LENGTH];
    char *tokens[MAX_TOKENS], *cmds[MAX_CMD], *cmd, *token;

    fgets(str, BUFFER_LENGTH, stdin);

    cmd = strtok(str, ";|");
    int i1 = 0, i2 = 0;
    while (cmd != NULL) {
        cmds[i1++] = cmd;
        cmd = strtok(NULL, ";|");
    }

    for (int i = 0; i < i1; i++) {
        token = strtok(cmds[i], " ");

        while (token != NULL) {
            tokens[i2++] = token;
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < i2; i++)
        printf("%s\n", tokens[i]);


    return 0;
}
