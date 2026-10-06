// laboratorio.c (sesión 1)
#include "uart.h"

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
