#include <stdio.h>

static int incrementar(int x) {
    return x + 1;
}

static int duplicar(int x) {
    return x * 2;
}

int main(void) {
    int valor = 4;
    printf("incrementar = %d\n", incrementar(valor));
    printf("duplicar = %d\n", duplicar(valor));
    return 0;
}
