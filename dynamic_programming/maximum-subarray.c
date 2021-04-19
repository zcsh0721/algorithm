//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
int maxSubArray(int *nums, int numsSize) {

    int max = INT_MIN;
    for (int i = 0, currentSum = 0; i < numsSize; ++i) {
        currentSum += *(nums + i);
        max = fmax(max, currentSum);
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return max;
}