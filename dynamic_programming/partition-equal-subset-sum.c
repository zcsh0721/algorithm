//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

bool canPartition(int *nums, int numsSize) {

    int sum = 0;
    for (int i = 0; i < numsSize; ++i) sum += nums[i];
    if ((sum & 1) == 1) return false;

    int length = sum >> 1;
    bool dp[length + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > length) return false;
        for (int j = length; j > 0 && j > nums[i]; --j) {
            if (dp[j] == false && dp[j - nums[i]] == true) {
                dp[j] = true;
            }
        }
        dp[nums[i]] = true;
    }
    return dp[length];
}


int main() {
    int value[] = {1, 5, 11, 5};
    printf("result=%d\n", canPartition(value, 4));
    return 0;
}