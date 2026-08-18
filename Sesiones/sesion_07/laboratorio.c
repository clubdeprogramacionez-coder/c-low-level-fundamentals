#include <stdio.h>

int suma(int a, int b) {
    int local = a + b;
    return local;
}

int main(void) {
    int x = 40;
    int y = 2;
    printf("suma = %d\n", suma(x, y));
    return 0;
}
