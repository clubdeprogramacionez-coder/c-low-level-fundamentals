#include <stdio.h>

int dato_global = 7;
int dato_bss;
const char *txt = "RISC-V";
static int dato_static = 11;

int main(void) {
    int local = 99;

    printf("dato_global = %d\n", dato_global);
    printf("dato_bss = %d\n", dato_bss);
    printf("txt = %s\n", txt);
    printf("dato_static = %d\n", dato_static);
    printf("local = %d\n", local);
    return 0;
}
