// laboratorio.c (sesión 1)
#include "uart.h"

#define UART0_BASE 0x10000000
#define UART0_DR   ((volatile unsigned char *)(UART0_BASE + 0))
#define UART0_LSR  ((volatile unsigned char *)(UART0_BASE + 5))

void uart_init(void) {
    /* La UART en QEMU virt está precargada por defecto */
}

void uart_putc(char c) {
    /* En QEMU virt se puede escribir directamente en el registro DR */
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

void _start(void) {
    uart_init();
    uart_puts("\n====================================\n");
    uart_puts("  Hola, mundo RISC-V Bare-Metal!  \n");
    uart_puts("====================================\n\n");

    for (;;) {
        char c = uart_getc();
        if (c != 0) {
            uart_putc(c); /* Echo de caracteres ingresados */
        }
    }
}
    }
}
