#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *nums = calloc(4, sizeof(int));
    if (!nums) {
        printf("calloc fallido\n");
        return 1;
    }

    for (int i = 0; i < 4; ++i) {
        nums[i] = i + 1;
    }

    nums = realloc(nums, sizeof(int) * 6);
    if (!nums) {
        printf("realloc fallido\n");
        return 1;
    }

    nums[4] = 99;
    nums[5] = 100;

    for (int i = 0; i < 6; ++i) {
        printf("nums[%d] = %d\n", i, nums[i]);
    }

    free(nums);
    return 0;
}
