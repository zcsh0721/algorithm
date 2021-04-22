#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int minCostClimbingStairs(int *cost, int costSize) {
    int dp[costSize + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < costSize; ++i) {
        dp[i] = fmin(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return fmin(dp[costSize - 1], dp[costSize - 2]);
}