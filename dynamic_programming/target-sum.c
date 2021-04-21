//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int findTargetSumWays(int *nums, int numsSize, int target) {
    int dp[2][2001];
    memset(dp, 0, sizeof(dp));

    dp[0][1000 + nums[0]] = 1;
    dp[0][1000 - nums[0]] += 1;

    int index = 1, preIndex = 0;
    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < 2001; ++j) {
            if (dp[preIndex][j] != 0) {
                dp[index][j + nums[i]] += dp[preIndex][j];
                dp[index][j - nums[i]] += dp[preIndex][j];
            }
        }

        memset(dp[preIndex], 0, sizeof(dp[0]));
        preIndex ^= 1;
        index ^= 1;
    }

    return dp[preIndex][1000 + target];
}