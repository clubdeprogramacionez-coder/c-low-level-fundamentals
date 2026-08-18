#include <stdio.h>

static int sumar(int a, int b) {
    return a + b;
}

static int restar(int a, int b) {
    return a - b;
}

static int multiplicar(int a, int b) {
    return a * b;
}

static int operar(int a, int b, int (*fn)(int, int)) {
    return fn(a, b);
}

int main(void) {
    int (*ops[3])(int, int) = {sumar, restar, multiplicar};

    printf("sumar = %d\n", operar(10, 4, ops[0]));
    printf("restar = %d\n", operar(10, 4, ops[1]));
    printf("multiplicar = %d\n", operar(10, 4, ops[2]));

    return 0;
}
