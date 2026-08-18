#include <stdio.h>

/**
 * Sesión 1: Introducción a Arquitecturas y Modelo de Memoria
 * 
 * Práctica: Explorar tamaños de segmentos y variables globales
 * 
 * Instrucciones:
 * 1. Compila este archivo
 * 2. Ejecuta: riscv64-unknown-elf-objdump -h practica
 * 3. Compara tamaños de .text, .data y .bss
 * 4. Compila y ejecuta con: qemu-riscv64 ./practica
 */

// Variable global inicializada -> va a .data
int contador_inicializado = 10;

// Variable global NO inicializada -> va a .bss
int contador_no_inicializado;

int main(void) {
    printf("=== Exploración de Segmentos de Memoria ===\n");
    printf("contador_inicializado = %d (en .data)\n", contador_inicializado);
    printf("contador_no_inicializado = %d (en .bss, inicialmente 0)\n", contador_no_inicializado);
    
    contador_no_inicializado = 42;
    printf("Después de asignar: contador_no_inicializado = %d\n", contador_no_inicializado);
    
    return 0;
}
