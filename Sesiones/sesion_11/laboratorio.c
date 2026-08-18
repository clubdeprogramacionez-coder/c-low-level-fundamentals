#include <stdio.h>

union Valor {
    int entero;
    unsigned char bytes[4];
};

int main(void) {
    union Valor v = { .entero = 0x01020304 };
    printf("entero = 0x%08x\n", v.entero);
    printf("bytes = %02x %02x %02x %02x\n",
           v.bytes[0], v.bytes[1], v.bytes[2], v.bytes[3]);
    return 0;
}
