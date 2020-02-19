#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    /**
    int i = 0;
    const char *user_env = "USER=";
    while (envp[i] != NULL) {
        if (strncmp(user_env, envp[i], 5) == 0) {
            printf("Hello %s\n", envp[i] + 5);
            return 0;
        }
        i++;
    }**/
    printf("Hello %s\n", getenv("USER"));
    return 0;
}
