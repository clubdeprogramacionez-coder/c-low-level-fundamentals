#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 3: Operadores Bit a Bit y Manipulación de Máscaras
 * 
 * Laboratorio: Simular registro GPIO de 8 bits y funciones de manipulación
 */

// Definir máscaras manuales
#define BIT_0 (1 << 0)  // 0b00000001
#define BIT_1 (1 << 1)  // 0b00000010
#define BIT_2 (1 << 2)  // 0b00000100
#define BIT_3 (1 << 3)  // 0b00001000
#define BIT_7 (1 << 7)  // 0b10000000

// Funciones de manipulación de bits
void set_bit(uint8_t *reg, int n) {
    *reg |= (1 << n);
}

void clear_bit(uint8_t *reg, int n) {
    *reg &= ~(1 << n);
}

void toggle_bit(uint8_t *reg, int n) {
    *reg ^= (1 << n);
}

int check_bit(uint8_t reg, int n) {
    return (reg >> n) & 1;
}

int main(void) {
    uint8_t gpio_registro = 0;  // Registro GPIO de 8 bits
    
    printf("=== Simulación de Registro GPIO (8 bits) ===\n");
    printf("Inicial: 0x%02X (0b%08d)\n\n", gpio_registro, gpio_registro);
    
    // Set bits
    set_bit(&gpio_registro, 0);
    printf("Después de set_bit(0): 0x%02X (0b%08d)\n", gpio_registro, gpio_registro);
    
    set_bit(&gpio_registro, 3);
    printf("Después de set_bit(3): 0x%02X (0b%08d)\n", gpio_registro, gpio_registro);
    
    set_bit(&gpio_registro, 7);
    printf("Después de set_bit(7): 0x%02X (0b%08d)\n\n", gpio_registro, gpio_registro);
    
    // Check bits
    printf("check_bit(0) = %d\n", check_bit(gpio_registro, 0));
    printf("check_bit(3) = %d\n", check_bit(gpio_registro, 3));
    printf("check_bit(7) = %d\n", check_bit(gpio_registro, 7));
    printf("check_bit(2) = %d (no debería estar set)\n\n", check_bit(gpio_registro, 2));
    
    // Toggle bits
    toggle_bit(&gpio_registro, 0);
    printf("Después de toggle_bit(0): 0x%02X\n", gpio_registro);
    
    toggle_bit(&gpio_registro, 7);
    printf("Después de toggle_bit(7): 0x%02X\n\n", gpio_registro);
    
    // Clear bits
    clear_bit(&gpio_registro, 3);
    printf("Después de clear_bit(3): 0x%02X\n", gpio_registro);
    
    // Operadores lógicos bit a bit
    printf("\n=== Operadores Lógicos ===\n");
    uint8_t a = 0b10101010;  // 0xAA
    uint8_t b = 0b01010101;  // 0x55
    
    printf("a = 0x%02X (0b%08d)\n", a, a);
    printf("b = 0x%02X (0b%08d)\n", b, b);
    printf("a & b = 0x%02X (0b%08d) [AND]\n", a & b, a & b);
    printf("a | b = 0x%02X (0b%08d) [OR]\n", a | b, a | b);
    printf("a ^ b = 0x%02X (0b%08d) [XOR]\n", a ^ b, a ^ b);
    printf("~a   = 0x%02X (0b%08d) [NOT]\n", ~a, ~a);
    
    // Desplazamientos
    printf("\n=== Desplazamientos ===\n");
    uint8_t c = 0b00000011;  // 3
    printf("c = 0x%02X\n", c);
    printf("c << 1 = 0x%02X (desplazamiento izquierdo)\n", c << 1);
    printf("c << 3 = 0x%02X\n", c << 3);
    printf("c >> 1 = 0x%02X (desplazamiento derecho)\n", c >> 1);
    
    return 0;
}
