#include <stdio.h>
#include <stdlib.h>


static int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

static void two_sum(int *nums, int low, int high, int target, int **results, int *count)
{
    while (low < high) {
        int sum = nums[low] + nums[high];
        if (sum < target) {
            low++;
        } else if (sum > target) {
            high--;
        } else {
            results[*count] = malloc(3 * sizeof(int));
            results[*count][0] = -target;
            results[*count][1] = nums[low];
            results[*count][2] = nums[high];
            (*count)++;
            while (++low < high && nums[low] == nums[low - 1]) {}
            while (--high > low && nums[high] == nums[high + 1]) {}
        }
    }
}

/**
 ** Return an array of arrays of size *returnSize.
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (numsSize < 3) {
        return NULL;
    }

    qsort(nums, numsSize, sizeof(*nums), compare);

    *returnSize = 0;
    int i, j, capacity = 50000;
    int **results = malloc(capacity * sizeof(int *));
    for (i = 0; i < numsSize - 2; i++) {
        if (i == 0 || i > 0 && nums[i] != nums[i - 1]) {
            two_sum(nums, i + 1, numsSize - 1, -nums[i], results, returnSize);
        }
    }

    *returnColumnSizes = malloc(*returnSize * sizeof(int *));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return results;
}

int main(void)
{
    int i, count;
    //int nums[] = { -1, 0, 1, 2, -1, -4 };
    //int nums[] = { 0, 0, 0 };
    //int nums[] = { -1, 0, 1, 0 };
    int nums[] = {-2,0,0,2,2};
    int **triplets = threeSum(nums, sizeof(nums) / sizeof(*nums), &count);
    for (i = 0; i < count; i++) {
        printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);
    }

    return 0;
}
