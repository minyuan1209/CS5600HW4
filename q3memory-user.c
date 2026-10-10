#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Usage: ./memory-user <megabytes> [seconds]
// Allocates <megabytes> MB and keeps touching every entry.
// Runs forever unless [seconds] is given.

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "usage: %s <megabytes> [seconds]\n", argv[0]);
        return 1;
    }

    long mb = strtol(argv[1], NULL, 10);
    long seconds = (argc == 3) ? strtol(argv[2], NULL, 10) : 0;
    if (mb <= 0 || seconds < 0) {
        fprintf(stderr, "megabytes must be > 0 and seconds must be >= 0\n");
        return 1;
    }

    size_t bytes = (size_t)mb * 1024 * 1024;
    size_t n = bytes / sizeof(int);

    int *arr = malloc(bytes);
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    // The PID is handy for later questions (e.g. pmap).
    printf("pid %d: allocated %ld MB\n", (int)getpid(), mb);
    if (seconds > 0)
        printf("running for %ld seconds\n", seconds);
    else
        printf("running until killed (Ctrl-C)\n");

    time_t start = time(NULL);
    while (seconds == 0 || time(NULL) - start < seconds) {
        // Touch every entry so the OS must back it with real memory.
        for (size_t i = 0; i < n; i++)
            arr[i] = (int)i;
    }

    free(arr);
    return 0;
}
