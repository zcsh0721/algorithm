//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int uniquePaths(int m, int n) {
    int *dp = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) dp[i] = 1;
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[j] += dp[j - 1];
    return dp[n - 1];
}