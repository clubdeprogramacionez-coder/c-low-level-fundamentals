#include <stdio.h>

int global_init = 10;
int global_uninit;
const char *mensaje = "hola";

int main(void) {
    static int contador = 0;
    int local = 42;

    printf("global_init = %d\n", global_init);
    printf("global_uninit = %d\n", global_uninit);
    printf("mensaje = %s\n", mensaje);
    printf("local = %d\n", local);
    printf("contador = %d\n", contador);
    return 0;
}
