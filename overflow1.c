#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *data = malloc(100 * sizeof(int));   // valid indexes: 0 to 99
    data[100] = 0;                           // one past the end
    free(data);
    return 0;
}