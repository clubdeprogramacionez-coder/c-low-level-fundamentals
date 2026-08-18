#include <stdio.h>

static int suma(int a, int b) {
    return a + b;
}

int main(void) {
    int x = 3;
    int y = 4;
    printf("x = %d, y = %d\n", x, y);
    printf("resultado = %d\n", suma(x, y));
    return 0;
}
