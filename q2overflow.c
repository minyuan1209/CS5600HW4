#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: %s <username>\n", argv[0]);
        return 1;
    }

    // BUG: strlen() does not count the '\0' terminator
    char *username = malloc(strlen(argv[1]));
    strcpy(username, argv[1]);   // writes strlen + 1 bytes

    printf("Welcome, %s!\n", username);
    free(username);
    return 0;
}