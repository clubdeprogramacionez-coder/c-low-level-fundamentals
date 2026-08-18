#include <stdio.h>

int maximo(int a, int b, int c) {
    int mayor = a;
    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;
    return mayor;
}

int main(void) {
    printf("maximo = %d\n", maximo(3, 9, 5));
    return 0;
}
