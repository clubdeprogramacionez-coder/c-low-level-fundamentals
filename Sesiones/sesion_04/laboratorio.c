#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 4: Macros del Preprocesador y Constantes de Hardware
 * 
 * Laboratorio: Usar macros para manipulación de bits y hardware
 */

// Definir direcciones base de periféricos
#define UART_BASE       0x10000000
#define GPIO_BASE       0x10001000
#define TIMER_BASE      0x10002000

// Definir macros de manipulación de bits
#define SET_BIT(reg, n)     ((reg) |= (1 << (n)))
#define CLEAR_BIT(reg, n)   ((reg) &= ~(1 << (n)))
#define TOGGLE_BIT(reg, n)  ((reg) ^= (1 << (n)))
#define CHECK_BIT(reg, n)   (((reg) >> (n)) & 1)
#define EXTRACT(reg, p, n)  (((reg) >> (p)) & ((1 << (n)) - 1))

// Macros más complejos con declaraciones
#define SWAP(a, b) do { \
    typeof(a) temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Macro para contar elementos de un array
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main(void) {
    printf("=== Macros del Preprocesador ===\n\n");
    
    // Mostrar direcciones de periféricos
    printf("Direcciones de Periféricos:\n");
    printf("  UART_BASE  = 0x%08X\n", UART_BASE);
    printf("  GPIO_BASE  = 0x%08X\n", GPIO_BASE);
    printf("  TIMER_BASE = 0x%08X\n\n", TIMER_BASE);
    
    // Usar macros de manipulación de bits
    uint32_t registro = 0x00000000;
    printf("Manipulación de Bits con Macros:\n");
    printf("Inicial: 0x%08X\n", registro);
    
    SET_BIT(registro, 0);
    printf("SET_BIT(0):   0x%08X\n", registro);
    
    SET_BIT(registro, 4);
    printf("SET_BIT(4):   0x%08X\n", registro);
    
    TOGGLE_BIT(registro, 0);
    printf("TOGGLE_BIT(0): 0x%08X\n", registro);
    
    CLEAR_BIT(registro, 4);
    printf("CLEAR_BIT(4): 0x%08X\n\n", registro);
    
    // Verificar bits
    printf("CHECK_BIT(0) = %d\n", CHECK_BIT(registro, 0));
    printf("CHECK_BIT(4) = %d\n\n", CHECK_BIT(registro, 4));
    
    // Usar macros MIN/MAX
    int a = 10, b = 20;
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("MAX(%d, %d) = %d\n\n", a, b, MAX(a, b));
    
    // Usar ARRAY_SIZE
    int arr[] = {1, 2, 3, 4, 5};
    printf("Array: { ");
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("ARRAY_SIZE(arr) = %zu\n\n", ARRAY_SIZE(arr));
    
    // Usar SWAP
    printf("SWAP example:\n");
    a = 5; b = 15;
    printf("Antes: a=%d, b=%d\n", a, b);
    SWAP(a, b);
    printf("Después: a=%d, b=%d\n", a, b);
    
    return 0;
}
