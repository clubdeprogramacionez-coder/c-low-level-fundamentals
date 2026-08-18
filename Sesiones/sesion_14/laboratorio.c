#include <stdio.h>

int sumar(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int operar(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

int main(void) {
    printf("sumar = %d\n", operar(3, 4, sumar));
    printf("multiplicar = %d\n", operar(3, 4, multiplicar));
    return 0;
}
