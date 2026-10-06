#include "uart.h"

#define UART0_BASE 0x10000000
#define UART0_DR   ((volatile unsigned char *)(UART0_BASE + 0))
#define UART0_LSR  ((volatile unsigned char *)(UART0_BASE + 5))

void uart_init(void) {
    /* Inicialización de la UART */
}

void uart_putc(char c) {
    *UART0_DR = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

char uart_getc(void) {
    if (*UART0_LSR & 0x01) {
        return *UART0_DR;
    }
    return 0;
}

/* Punto de entrada desde ensamblador */
void main_c(void) {
    uart_init();
    uart_puts("\n====================================\n");
    uart_puts("  Hola, mundo RISC-V Bare-Metal!  \n");
    uart_puts("====================================\n\n");

    for (;;) {
        char c = uart_getc();
        if (c != 0) {
            uart_putc(c); /* Echo */
        }
    }
}

/* Rutina de arranque en ensamblador para configurar la pila */
__asm__(
    ".section .text\n"
    ".global _start\n"
    "_start:\n"
    "    la sp, stack_top\n"  /* Cargar dirección tope de la pila */
    "    tail main_c\n"        /* Saltar a la función en C */
    ".section .bss\n"
    ".align 4\n"
    "stack_bottom:\n"
    "    .skip 4096\n"         /* Reservar 4 KB para la pila */
    "stack_top:\n"
);
