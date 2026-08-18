#include <stdio.h>

int f(int x) {
    if (x > 0) return 1;
    return 0;
}

int main(void) {
    printf("f(5) = %d\n", f(5));
    printf("f(-1) = %d\n", f(-1));
    return 0;
}
