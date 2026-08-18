#include <stdio.h>
#include <stdlib.h>

void liberar_matriz(int **m, int filas) {
    for (int i = 0; i < filas; ++i) {
        free(m[i]);
    }
    free(m);
}

int main(void) {
    int filas = 2;
    int columnas = 3;
    int **m = malloc(sizeof(int *) * filas);

    if (!m) {
        return 1;
    }

    for (int i = 0; i < filas; ++i) {
        m[i] = malloc(sizeof(int) * columnas);
        for (int j = 0; j < columnas; ++j) {
            m[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            printf("m[%d][%d] = %d\n", i, j, m[i][j]);
        }
    }

    liberar_matriz(m, filas);
    return 0;
}
