#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static int rob(int* nums, int numsSize)
{
    int i;
    int taken = 0;
    int untaken = 0;
    /* Record max profits of nums[0...i] respectively */
    for (i = 0; i < numsSize; i++) {
        int last_taken = taken;
        /* Taken or untaken nums[i] */
        /* last taken + nums[i] */
        taken = untaken + nums[i];
        /* max(last untaken, last taken) */
        untaken = max(last_taken, untaken);
    }

    return max(taken, untaken);
}

int main(int argc, char **argv)
{
    int i, count = argc - 1;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%d\n", rob(nums, count));
    return 0;
}
