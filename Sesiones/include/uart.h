#ifndef UART_H
#define UART_H

/**
 * uart.h - UART driver for RISC-V bare-metal on QEMU
 * 
 * This header provides basic UART I/O functions for
 * communicating with QEMU's simulated UART device.
 */

#include <stdint.h>

/* UART Base Address (QEMU virt machine) */
#define UART_BASE 0x10000000

/* UART Register Offsets */
#define UART_RHR    0  /* Receiver Holding Register (read) */
#define UART_THR    0  /* Transmitter Holding Register (write) */
#define UART_IER    1  /* Interrupt Enable Register */
#define UART_ISR    2  /* Interrupt Status Register */
#define UART_FCR    2  /* FIFO Control Register */
#define UART_LCR    3  /* Line Control Register */
#define UART_MCR    4  /* Modem Control Register */
#define UART_LSR    5  /* Line Status Register */
#define UART_MSR    6  /* Modem Status Register */
#define UART_SCR    7  /* Scratch Register */

/* Line Status Register bits */
#define UART_LSR_RX_READY   0x01  /* Data Ready */
#define UART_LSR_TX_EMPTY   0x20  /* Transmitter Empty */

/**
 * uart_init() - Initialize UART
 * 
 * Sets up the UART for basic I/O operations.
 * Configure baud rate, parity, stop bits, etc.
 */
void uart_init(void);

/**
 * uart_putc() - Write a single character
 * 
 * @c: Character to send
 */
void uart_putc(char c);

/**
 * uart_getc() - Read a single character
 * 
 * Returns: Character read, or 0 if no data available
 */
char uart_getc(void);

/**
 * uart_puts() - Write a null-terminated string
 * 
 * @s: String to send
 */
void uart_puts(const char *s);

/**
 * uart_puthex() - Write a hexadecimal number
 * 
 * @val: Value to print
 * @width: Number of digits (8, 16, 32, 64)
 */
void uart_puthex(uint64_t val, int width);

#endif /* UART_H */
