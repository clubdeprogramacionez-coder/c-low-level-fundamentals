#include <stdio.h>

static void handle_timer(void) {
    printf("timer expired\n");
}

static void handle_uart(void) {
    printf("uart ready\n");
}

int main(void) {
    void (*handlers[2])(void) = {handle_timer, handle_uart};

    for (int i = 0; i < 2; ++i) {
        handlers[i]();
    }

    return 0;
}
