#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;   // array holding the elements
    int size;    // number of elements stored
} vector;

void vector_init(vector *v) {
    v->data = NULL;
    v->size = 0;
}

// add one entry: grow the array by one int with realloc()
void vector_add(vector *v, int value) {
    int *tmp = realloc(v->data, (v->size + 1) * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "realloc failed\n");
        exit(1);
    }
    v->data = tmp;
    v->data[v->size] = value;
    v->size++;
}

int vector_get(vector *v, int index) {
    return v->data[index];
}

void vector_free(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
}

int main(void) {
    vector v;
    vector_init(&v);

    for (int i = 0; i < 10; i++)
        vector_add(&v, i * 10);

    for (int i = 0; i < v.size; i++)
        printf("%d ", vector_get(&v, i));
    printf("\n");

    vector_free(&v);
    return 0;
}