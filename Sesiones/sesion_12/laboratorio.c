#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *datos = malloc(sizeof(int) * 5);
    if (!datos) {
        printf("Error: malloc fallido\n");
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        datos[i] = i * 10;
    }

    for (int i = 0; i < 5; ++i) {
        printf("datos[%d] = %d\n", i, datos[i]);
    }

    free(datos);
    return 0;
}
