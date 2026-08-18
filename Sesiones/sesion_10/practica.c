#include <stddef.h>
#include <stdio.h>

struct Registro {
    char flag;
    int valor;
    char estado;
};

int main(void) {
    printf("sizeof(struct Registro) = %zu\n", sizeof(struct Registro));
    printf("offset flag = %zu\n", offsetof(struct Registro, flag));
    printf("offset valor = %zu\n", offsetof(struct Registro, valor));
    printf("offset estado = %zu\n", offsetof(struct Registro, estado));
    return 0;
}
