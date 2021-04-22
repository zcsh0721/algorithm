#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int massage(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int dp[numsSize + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = nums[0];

    for (int i = 2; i < numsSize + 1; ++i) {
        dp[i] = fmax(nums[i - 1] + dp[i - 2], dp[i - 1]);
    }
    return dp[numsSize];
}