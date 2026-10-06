// laboratorio.c (sesión 1)
#include "uart.h"

/* Definición de registros MMIO para la UART de QEMU virt */
#define UART0_BASE 0x10000000
#define UART0_DR   ((volatile unsigned char *)(UART0_BASE + 0))
#define UART0_LSR  ((volatile unsigned char *)(UART0_BASE + 5))

void uart_init(void) {
    /* La UART en QEMU virt ya viene inicializada por defecto */
}

void uart_putc(char c) {
    /* Esperar hasta que el registro de transmisión esté vacío (LSR bit 5) */
    while ((*UART0_LSR & 0x20) == 0);
    *UART0_DR = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

char uart_getc(void) {
    /* Si hay datos listos para leer (LSR bit 0) */
    if (*UART0_LSR & 0x01) {
        return *UART0_DR;
    }
    return 0;
}

void _start(void) {
    uart_init();
    uart_puts("Hola, mundo RISC-V bare-metal\n");
    uart_puts("QEMU virt + UART MMIO\n");

    for (;;) {
        char c = uart_getc();
        if (c != 0) {
            uart_putc(c);
        }
    }
}
