#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"

int climbStairs(int n) {
    if (n == 0) return 0;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}