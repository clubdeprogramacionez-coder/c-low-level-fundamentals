#include <stdio.h>

static int irq_pending = 0;

static void isr(void) {
    irq_pending = 1;
    printf("IRQ recibida\n");
}

int main(void) {
    isr();

    if (irq_pending) {
        printf("Se atendio la interrupcion\n");
    }

    return 0;
}
