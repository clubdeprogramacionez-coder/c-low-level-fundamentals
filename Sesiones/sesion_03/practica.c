#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 3: Operadores Bit a Bit - Práctica
 * 
 * Práctica: Implementar popcount() (contar bits en 1)
 * 
 * Instrucciones:
 * 1. Implementa popcount() sin usar bibliotecas externas
 * 2. Prueba con varios números
 * 3. Compila y ejecuta en QEMU
 * 
 * Pista: Un número con k bits en 1 tendrá popcount = k
 */

/**
 * popcount: Cuenta el número de bits en 1 en un número
 * Ejemplo: popcount(0b01010101) = 4
 */
int popcount(uint64_t n) {
    int count = 0;
    while (n) {
        count += n & 1;    // Suma 1 si el bit menos significativo es 1
        n >>= 1;           // Desplaza derecha
    }
    return count;
}

// Alternativa más eficiente: Brian Kernighan's Algorithm
int popcount_bk(uint64_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Limpia el bit más bajo en 1
        count++;
    }
    return count;
}

int main(void) {
    printf("=== Contador de Bits (popcount) ===\n\n");
    
    uint64_t test_values[] = {
        0b0,
        0b1,
        0b11,
        0b111,
        0b1111,
        0b10101010,
        0b11111111,
        0xFFFFFFFFFFFFFFFFULL  // Todos los bits en 1
    };
    
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    for (int i = 0; i < num_tests; i++) {
        uint64_t value = test_values[i];
        int count1 = popcount(value);
        int count2 = popcount_bk(value);
        
        printf("0x%016lX: popcount = %d, popcount_bk = %d\n", value, count1, count2);
    }
    
    return 0;
}
