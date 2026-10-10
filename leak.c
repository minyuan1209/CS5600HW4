#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(int));   // allocate memory
    *p = 42;
    printf("%d\n", *p);
    return 0;                       // exit without calling free(p)
}