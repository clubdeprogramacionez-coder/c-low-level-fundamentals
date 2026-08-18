#include <stdio.h>

long suma3(long a, long b, long c) {
    return a + b + c;
}

int main(void) {
    printf("%ld\n", suma3(10L, 20L, 30L));
    return 0;
}
