#include <stdint.h>
#include <stdio.h>

#define GPIO_REGS 8u

static void set_mask(uint32_t *regs, uint32_t mask) {
    regs[0] |= mask;
}

static void clear_mask(uint32_t *regs, uint32_t mask) {
    regs[0] &= ~mask;
}

int main(void) {
    uint32_t regs[GPIO_REGS] = {0};
    uint32_t mask = 0x05u;

    set_mask(regs, mask);
    printf("estado = 0x%08x\n", regs[0]);

    clear_mask(regs, 0x01u);
    printf("estado final = 0x%08x\n", regs[0]);

    return 0;
}
