#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int add(int a, int b) {
    if (1000000007 - a <= b)
        return b - (1000000007 - a);
    return a + b;
}

int waysToStep(int n) {
    if (n <= 3) return pow(2, n - 1);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < n + 1; ++i) {
        dp[i] = add(add(dp[i - 1], dp[i - 2]), dp[i - 3]);
    }
    return dp[n];
}