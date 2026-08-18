#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 4: Macros - Práctica
 * 
 * Práctica: Refactorizar código de Sesión 3 usando macros
 * 
 * Instrucciones:
 * 1. Define los macros SET_BIT, CLEAR_BIT, TOGGLE_BIT, CHECK_BIT
 * 2. Reescribe el simulador GPIO usando estos macros
 * 3. Compila con: riscv64-unknown-elf-gcc -E practica.c > practica_expanded.c
 *    para ver la expansión del preprocesador
 */

#define SET_BIT(reg, n)     ((reg) |= (1 << (n)))
#define CLEAR_BIT(reg, n)   ((reg) &= ~(1 << (n)))
#define TOGGLE_BIT(reg, n)  ((reg) ^= (1 << (n)))
#define CHECK_BIT(reg, n)   (((reg) >> (n)) & 1)

int main(void) {
    uint8_t led_control = 0x00;  // Registro de control de LEDs
    
    printf("=== Simulador GPIO Refactorizado ===\n\n");
    printf("Estado inicial: 0x%02X\n\n", led_control);
    
    // Activar LEDs 0, 2, 4
    printf("Activar LEDs 0, 2, 4:\n");
    SET_BIT(led_control, 0);
    SET_BIT(led_control, 2);
    SET_BIT(led_control, 4);
    printf("  Registro: 0x%02X (0b%08d)\n\n", led_control, led_control);
    
    // Verificar estado
    printf("Estado de LEDs:\n");
    for (int i = 0; i < 8; i++) {
        printf("  LED %d: %s\n", i, CHECK_BIT(led_control, i) ? "ON" : "OFF");
    }
    
    // Alternar LED 2
    printf("\nAlternar LED 2:\n");
    TOGGLE_BIT(led_control, 2);
    printf("  Registro: 0x%02X\n\n", led_control);
    
    // Desactivar LED 4
    printf("Desactivar LED 4:\n");
    CLEAR_BIT(led_control, 4);
    printf("  Registro: 0x%02X\n\n", led_control);
    
    // Mostrar estado final
    printf("Estado final de LEDs:\n");
    for (int i = 0; i < 8; i++) {
        printf("  LED %d: %s\n", i, CHECK_BIT(led_control, i) ? "ON" : "OFF");
    }
    
    return 0;
}
