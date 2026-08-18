#include <stdio.h>

static int validar(int x) {
    if (x < 0) {
        printf("valor invalido: %d\n", x);
        return -1;
    }
    return x * 2;
}

int main(void) {
    printf("resultado = %d\n", validar(7));
    printf("resultado = %d\n", validar(-3));
    return 0;
}
