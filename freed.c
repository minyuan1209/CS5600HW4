#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *data = malloc(100 * sizeof(int));
    data[50] = 42;
    free(data);                     // memory released
    printf("%d\n", data[50]);       // read after free
    return 0;
}