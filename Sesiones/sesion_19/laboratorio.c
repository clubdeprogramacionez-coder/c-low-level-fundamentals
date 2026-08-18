#include <stdio.h>

static int procesar(int x) {
    return x * 2;
}

int main(void) {
    printf("resultado = %d\n", procesar(5));
    return 0;
}
