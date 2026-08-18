#include <stdio.h>

/**
 * Sesión 1: Introducción a Arquitecturas y Modelo de Memoria
 * 
 * Laboratorio: Cross-compile "Hola Mundo" y explorar segmentos de proceso
 * 
 * Objetivo: Comprender la estructura de memoria de un programa RISC-V
 */

int main(void) {
    printf("Hola, Mundo - RISC-V 64-bit\n");
    printf("Este programa fue compilado como:\n");
    printf("  Architecture: RISC-V 64-bit (rv64gc)\n");
    printf("  ABI: LP64 (64-bit pointers)\n");
    printf("  Emulador: QEMU\n");
    
    return 0;
}
