#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 2: Tipos de Datos en C y Mapeo a Registros RISC-V
 * 
 * Laboratorio: Declarar variables de varios tipos y generar assembly
 * para ver cómo el compilador asigna registros
 */

int main(void) {
    // Tipos de datos estándar
    char c = 'A';
    short s = 1000;
    int i = 100000;
    long l = 9999999999L;
    
    // Tipos de tamaño fijo (stdint.h)
    uint8_t u8 = 255;
    uint16_t u16 = 65535;
    uint32_t u32 = 4294967295U;
    uint64_t u64 = 18446744073709551615ULL;
    
    // Tipos con signo
    int8_t s8 = -128;
    int16_t s16 = -32768;
    int32_t s32 = -2147483648;
    int64_t s64 = -9223372036854775807LL;
    
    // Punto flotante
    float f = 3.14159f;
    double d = 2.71828;
    
    // Punteros (8 bytes en rv64)
    void *p = &i;
    
    printf("=== Tamaños de Tipos en RISC-V 64-bit ===\n");
    printf("char       : %zu bytes\n", sizeof(char));
    printf("short      : %zu bytes\n", sizeof(short));
    printf("int        : %zu bytes\n", sizeof(int));
    printf("long       : %zu bytes\n", sizeof(long));
    printf("uint8_t    : %zu bytes\n", sizeof(uint8_t));
    printf("uint16_t   : %zu bytes\n", sizeof(uint16_t));
    printf("uint32_t   : %zu bytes\n", sizeof(uint32_t));
    printf("uint64_t   : %zu bytes\n", sizeof(uint64_t));
    printf("float      : %zu bytes\n", sizeof(float));
    printf("double     : %zu bytes\n", sizeof(double));
    printf("puntero    : %zu bytes\n", sizeof(void*));
    
    printf("\n=== Valores ===\n");
    printf("c = %c, s = %d, i = %d, l = %ld\n", c, s, i, l);
    printf("u8 = %u, u16 = %u, u32 = %u\n", u8, u16, u32);
    printf("f = %.5f, d = %.5f\n", f, d);
    printf("p = %p\n", p);
    
    return 0;
}
