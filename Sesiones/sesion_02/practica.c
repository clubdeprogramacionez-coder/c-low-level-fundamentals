#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 2: Tipos de Datos en C y Mapeo a Registros RISC-V
 * 
 * Práctica: Tabla de tipos → registros
 * 
 * Instrucciones:
 * 1. Compila con: riscv64-unknown-elf-gcc -S -O0 practica.c -o practica.s
 * 2. Abre practica.s y busca cómo el compilador asigna cada variable a registros
 * 3. Completa la tabla en el README
 */

uint32_t sumar_u32(uint32_t a, uint32_t b) {
    return a + b;  // Debería usar registros a0, a1 y retornar en a0
}

int64_t multiplicar_i64(int64_t x, int64_t y) {
    return x * y;  // Registros a0, a1 y retorno en a0
}

double calcular_promedio(double x, double y, double z) {
    return (x + y + z) / 3.0;  // Registros fa0, fa1, fa2 (floating point)
}

int main(void) {
    uint32_t resultado32 = sumar_u32(10, 20);
    printf("suma_u32(10, 20) = %u\n", resultado32);
    
    int64_t resultado64 = multiplicar_i64(100, 200);
    printf("multiplicar_i64(100, 200) = %ld\n", resultado64);
    
    double promedio = calcular_promedio(1.0, 2.0, 3.0);
    printf("promedio(1.0, 2.0, 3.0) = %.2f\n", promedio);
    
    return 0;
}
