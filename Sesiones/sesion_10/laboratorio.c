#include <stddef.h>
#include <stdio.h>

struct Persona {
    char inicial;
    int edad;
    double saldo;
};

int main(void) {
    struct Persona p = {'A', 25, 1200.50};
    printf("sizeof = %zu\n", sizeof(p));
    printf("offset inicial = %zu\n", offsetof(struct Persona, inicial));
    printf("offset edad = %zu\n", offsetof(struct Persona, edad));
    printf("offset saldo = %zu\n", offsetof(struct Persona, saldo));
    return 0;
}
