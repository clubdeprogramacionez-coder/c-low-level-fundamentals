#include <stdint.h>
#include <stdio.h>

#define GPIO_BASE 0x10000000UL
#define LED0 0x01u
#define LED1 0x02u

static void set_bit(volatile uint32_t *reg, uint32_t bit) {
    *reg |= bit;
}

static void clear_bit(volatile uint32_t *reg, uint32_t bit) {
    *reg &= ~bit;
}

static void toggle_bit(volatile uint32_t *reg, uint32_t bit) {
    *reg ^= bit;
}

int main(void) {
    volatile uint32_t *gpio = (volatile uint32_t *)GPIO_BASE;
    *gpio = 0;

    set_bit(gpio, LED0);
    printf("after LED0 -> 0x%08x\n", (unsigned int)*gpio);

    toggle_bit(gpio, LED0);
    printf("after toggle -> 0x%08x\n", (unsigned int)*gpio);

    set_bit(gpio, LED1);
    printf("after LED1 -> 0x%08x\n", (unsigned int)*gpio);

    clear_bit(gpio, LED0);
    printf("after clear LED0 -> 0x%08x\n", (unsigned int)*gpio);

    return 0;
}
