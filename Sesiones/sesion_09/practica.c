#include <stdio.h>

int suma_n(int n) {
    int total = 0;
    for (int i = 0; i <= n; ++i) {
        total += i;
    }
    return total;
}

int main(void) {
    printf("suma_n(5) = %d\n", suma_n(5));
    return 0;
}
