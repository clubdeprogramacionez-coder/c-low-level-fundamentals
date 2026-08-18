#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int filas = 3;
    int columnas = 4;
    int **matriz = malloc(sizeof(int *) * filas);

    if (!matriz) {
        return 1;
    }

    for (int i = 0; i < filas; ++i) {
        matriz[i] = malloc(sizeof(int) * columnas);
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = i * columnas + j;
        }
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < filas; ++i) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
